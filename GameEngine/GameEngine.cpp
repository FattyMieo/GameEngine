// GameEngine.cpp : Defines the entry point for the console application.
//
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

float timer = 0.0f;

void gameUpdate(float deltaTime)
{
	timer -= deltaTime;

	if (timer <= 0.0f)
	{
		timer = 0.1f;
		system("CLS");
		cout << "Delta Time: " << deltaTime << endl;
		cout << "FPS: " << 1.0f / deltaTime << endl;
	}
}

int main(void)
{
	GLFWwindow* window;
	bool useVSync = true;
	float lastUpdateTime = (float)glfwGetTime();

	// Initialize the Libraries
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(640, 480, "GameEngine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	// Enable / Disbale VSync
	glfwSwapInterval((useVSync ? 1 : 0));

	// Core Game Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		// Render here
		glClear(GL_COLOR_BUFFER_BIT);

		// Calculate delta time and FPS
		float deltaTime = (float)glfwGetTime() - lastUpdateTime;
		lastUpdateTime = (float)glfwGetTime();
		float fps = 1.0f / deltaTime;

		gameUpdate(deltaTime);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

    return 0;
}

