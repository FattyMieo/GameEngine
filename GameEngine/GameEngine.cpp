// GameEngine.cpp : Defines the entry point for the console application.
//
#include <GLFW/glfw3.h>
#include <Windows.h>
#include <GL/GLU.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include "FMODExtension.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MyApplication.h"
#include "Bitmap.h"

using namespace std;

const int RESOLUTION_X = 640;
const int RESOLUTION_Y = 480;

FMOD::System* m_fmodSystem;

void initFMOD()
{
	FMOD_RESULT result;
	unsigned int version;

	result = FMOD::System_Create(&m_fmodSystem);
	FMOD_ErrorCheck(result);

	result = m_fmodSystem->getVersion(&version);
	FMOD_ErrorCheck(result);

	if (version < FMOD_VERSION)
	{
		printf("FMOD Error! You are using an old version of FMOD.", version, FMOD_VERSION);
	}

	//Initialise fmod system
	result = m_fmodSystem->init(32, FMOD_INIT_NORMAL, 0);
	FMOD_ErrorCheck(result);
}

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

Application* app = new MyApplication();

float timer = 0.0f;

void gameUpdate(float deltaTime, GLFWwindow* window)
{
	app->Update(deltaTime);
	app->OnKeyDown(window);

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
	//Set random seed
	srand((unsigned int)time(NULL));

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

	//Setup FMOD
	initFMOD();
	app->InitFMOD(m_fmodSystem);

	// Run Application Start
	app->Start();

	// Core Game Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		// Render here
		glClear(GL_COLOR_BUFFER_BIT);

		// Calculate delta time and FPS
		float deltaTime = (float)glfwGetTime() - lastUpdateTime;
		lastUpdateTime = (float)glfwGetTime();
		float fps = 1.0f / deltaTime;

		gameUpdate(deltaTime, window);
		app->Draw();

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

    return 0;
}

