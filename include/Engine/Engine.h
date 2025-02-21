// Engine.h

#ifndef ENGINE_H
#define ENGINE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "imgui.h"

class Engine
{
public:
	Engine();
	~Engine();

	int Initialize();
	int CreateWindow(int width, int height, const char* title);
	static int InitializeGlad();

	static ImGuiIO& InitializeImGui();
	void InitializeImGuiRendering() const;
	static void ImGuiStartRender();
	static void ImGuiEndRender();
	static void CleanupImGui();
	void CleanupGLFW() const;

	void DisplayVersionInfo() const;

	[[nodiscard]] ImGuiIO& GetImGuiIO() const;
	[[nodiscard]] const char* GetEngineVersion() const;
	[[nodiscard]] const char* GetGLSLVersion() const;
	[[nodiscard]] GLFWwindow* GetWindow() const;

private:
	const char* glslVersion = "#version 330";
	const char* engineVersion = "v0.1.0-alpha";

	ImGuiIO& io;
	GLFWwindow* window = nullptr;
};

#endif
