#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ModuleA/ModuleA.h"
#include "ModuleB/ModuleB.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

int main()
{
    std::cout << "Hello from main!" << std::endl;
    ModuleAPrint();
    ModuleBPrint();

    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Error: GLFW initialization failed!" << std::endl;
        return -1;
    }

    const char* glslVersion = "#version 330";

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGL Template", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Error: Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    //glfwSwapInterval(1); // Enable vsync

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();

    // Initialize ImGui platform/renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion);

    // Variables for ImGui state
    bool showDemoWindow = true;
    bool showAnotherWindow = false;
    float sliderValue = 0.0f;
    ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll events
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Display ImGui demo window
        if (showDemoWindow)
        {
            ImGui::ShowDemoWindow(&showDemoWindow);
        }

        // 2. Create a custom window with various ImGui widgets
        {
            ImGui::Begin("Hello, world!");
            ImGui::Text("This is some useful text.");
            ImGui::Checkbox("Demo Window", &showDemoWindow);
            ImGui::Checkbox("Another Window", &showAnotherWindow);
            ImGui::SliderFloat("Slider", &sliderValue, 0.0f, 1.0f);
            ImGui::ColorEdit3("Clear Color", (float*)&clearColor);

            if (ImGui::Button("Press Me"))
            {
                std::cout << "Button pressed!" << std::endl;
            }
            ImGui::SameLine();
            ImGui::Text("next to button.");

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        // 3. Show another simple window if enabled
        if (showAnotherWindow)
        {
            ImGui::Begin("Another Window", &showAnotherWindow);
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
            {
                showAnotherWindow = false;
            }
            ImGui::End();
        }

        // End the ImGui frame, render it, and update the viewport
        ImGui::Render();
        int displayW;
        int displayH;
        glfwGetFramebufferSize(window, &displayW, &displayH);
        glViewport(0, 0, displayW, displayH);
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // Cleanup ImGui and GLFW.
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
