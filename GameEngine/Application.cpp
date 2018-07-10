#include "Application.h"
#include <iostream>
#include <cmath>

Application::Application()
{

}

Application::~Application()
{

}

Application& Application::GetInstance()
{
	static Application instance;
	return instance;
}

void Application::Start()
{
	//std::cout << "Application Started" << std::endl;
	m_dummySprite.LoadFromFile("../Media/Cat.bmp");
}

void Application::Update(float deltaTime)
{
	//std::cout << "Application Updated" << std::endl;

	time += deltaTime;
}

void Application::Draw()
{
	//std::cout << "Application Drawn" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_dummySprite.Draw
	(
		320.0f,
		240.0f,
		100.0f * time,
		0.25f * (sin(time + 1.0f) + 1.0f),
		0.25f * (sin(time + 1.0f) + 1.0f)
	);
	m_dummySprite.Draw
	(
		100.0f,
		240.0f,
		-15.0f * time,
		0.5f * (sin(time + 2.0f) + 0.25f),
		0.5f * (sin(time + 2.0f) + 0.25f)
	);
	m_dummySprite.Draw
	(
		220.0f,
		400.0f,
		20.0f * time,
		0.3f * (sin(time + 3.0f) + 0.5f),
		0.3f * (sin(time + 3.0f) + 0.5f)
	);
}