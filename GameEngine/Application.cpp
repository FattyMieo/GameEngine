#include "Application.h"
#include <GLFW/glfw3.h>
#include <iostream>

Application::Application()
{
	m_instance = new Application();
}

Application::~Application()
{
	delete m_instance;
}

Application* Application::GetInstance()
{
	return m_instance;
}

void Application::Start()
{
	std::cout << "Application Started" << std::endl;
}

void Application::Update(float deltaTime)
{
	std::cout << "Application Updated" << std::endl;
}

void Application::Draw()
{
	std::cout << "Application Drawn" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_dummySprite.Draw(320, 240);
	m_dummySprite.Draw(100, 240);
	m_dummySprite.Draw(220, 400);
}