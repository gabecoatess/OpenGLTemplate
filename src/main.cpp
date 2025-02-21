#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Engine.h"
#include "Engine/Time.h"

#include "imgui.h"

Engine* engine = nullptr;
Time* time = nullptr;

int main()
{
	engine = new Engine();
	time = new Time();

	if (engine->Initialize() == -1)
	{
		return -1;
	}

	// Main loop
	while (!glfwWindowShouldClose(engine->GetWindow()))
	{
		time->Update();
		glfwPollEvents();

		Engine::ImGuiStartRender();
		{
			ImGui::Begin("Debug");
			ImGui::Text("Frame rate: %d", time->GetFrameRate());
			ImGui::End();
		}

		glClearColor(0.45f, 0.55f, 0.6f, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		Engine::ImGuiEndRender();

		glfwSwapBuffers(engine->GetWindow());
	}

	if (engine != nullptr)
	{
		Engine::CleanupImGui();
		engine->CleanupGLFW();
	}

	return 0;
}
