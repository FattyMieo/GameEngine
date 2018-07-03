// GameEngine.cpp : Defines the entry point for the console application.
//
#include <GLFW/glfw3.h>
#include <Windows.h>
#include <GL/GLU.h>
#include <iostream>
#include "Application.h"

using namespace std;

const int RESOLUTION_X = 640;
const int RESOLUTION_Y = 480;

void onWindowResized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Use Ortho 2D View
	gluOrtho2D(0, width, 0, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

float timer = 0.0f;

void gameUpdate(float deltaTime)
{
	Application::GetInstance()->Update(deltaTime);

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

	// Set Ortho 2D View
	onWindowResized(window, RESOLUTION_X, RESOLUTION_Y);

	// Run Application Start
	Application::GetInstance()->Start();

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
		Application::GetInstance()->Draw();

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

    return 0;
}

