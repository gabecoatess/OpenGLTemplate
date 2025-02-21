// Engine.cpp

#include "Engine/Engine.h"

#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

Engine::Engine() : io(InitializeImGui())
{
	// Initialize ImGui
	InitializeImGui();
}

Engine::~Engine() = default;

int Engine::Initialize()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		std::cerr << "Error: GLFW initialization failed!" << std::endl;
		return -1;
	}

	// Initialize GLFW Window
	if (CreateWindow(1280, 720, "2DTileGame by Gabriel Coates") == -1)
	{
		return -1;
	}

	// Initialize GLAD
	if (InitializeGlad() == -1)
	{
		return -1;
	}

	DisplayVersionInfo();

	InitializeImGuiRendering();

	return 0;
}

int Engine::CreateWindow(int width, int height, const char* title)
{
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (!window)
	{
		std::cerr << "Error: GLFW window initialization failed!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	return 0;
}

int Engine::InitializeGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Error: GLAD initialization failed!" << std::endl;
		return -1;
	}

	return 0;
}

ImGuiIO& Engine::InitializeImGui()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	return ImGui::GetIO();
}

void Engine::InitializeImGuiRendering() const
{
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glslVersion);
}

void Engine::ImGuiStartRender()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Engine::ImGuiEndRender()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Engine::CleanupImGui()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Engine::CleanupGLFW() const
{
	if (window)
	{
		glfwDestroyWindow(window);
	}
	glfwTerminate();
}

void Engine::DisplayVersionInfo() const
{
	std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Engine Version: " << engineVersion << std::endl;
}

ImGuiIO& Engine::GetImGuiIO() const
{
	return io;
}

const char* Engine::GetEngineVersion() const
{
	return engineVersion;
}

const char* Engine::GetGLSLVersion() const
{
	return glslVersion;
}

GLFWwindow* Engine::GetWindow() const
{
	return window;
}
