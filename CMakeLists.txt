cmake_minimum_required(VERSION 3.10)
project(OpenGLTemplate VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL from the system
find_package(OpenGL REQUIRED)

include(FetchContent)

# Fetch GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

set(GLAD_DIR ${CMAKE_SOURCE_DIR}/external/glad)
add_library(glad_lib ${GLAD_DIR}/src/glad.c)
target_include_directories(glad_lib PUBLIC ${GLAD_DIR}/include)

# Fetch ImGui using MakeAvailable to avoid deprecated Populate.
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.91.8
)
FetchContent_MakeAvailable(imgui)

# Create a static library target for ImGui.
if (NOT TARGET imgui_lib)
    add_library(imgui_lib STATIC
            ${imgui_SOURCE_DIR}/imgui.cpp
            ${imgui_SOURCE_DIR}/imgui_draw.cpp
            ${imgui_SOURCE_DIR}/imgui_demo.cpp
            ${imgui_SOURCE_DIR}/imgui_tables.cpp
            ${imgui_SOURCE_DIR}/imgui_widgets.cpp
            ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
            ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    )
    # Make sure to add the GLFW include directory so that the backend can find <GLFW/glfw3.h>
    target_include_directories(imgui_lib PUBLIC
            ${imgui_SOURCE_DIR}
            ${imgui_SOURCE_DIR}/backends
            ${glfw_SOURCE_DIR}/include
    )
endif ()

# Automatically collect all .cpp files in the "src" folder (including nested modules).
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Create the executable target.
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add the include directory for your project’s headers.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link external libraries (OpenGL, GLFW, our custom GLAD, and ImGui).
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw glad_lib imgui_lib)