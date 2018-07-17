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
	Sprite s;
	s.LoadFromFile("../Media/Cat.bmp");

	m_Sprites.push_back(s);

	s.LoadFromFile("../Media/Dog.bmp");

	m_Sprites.push_back(s);

	s.LoadFromFile("../Media/Cat.bmp");

	m_Sprites.push_back(s);
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

	ExtendList::Get(m_Sprites, 0).Draw
	(
		320.0f,
		240.0f,
		100.0f * time,
		0.25f * (sin(time + 1.0f) + 1.0f),
		0.25f * (sin(time + 1.0f) + 1.0f)
	);
	
	ExtendList::Get(m_Sprites, 1).Draw
	(
		100.0f,
		240.0f,
		-15.0f * time,
		0.5f * (sin(time + 2.0f) + 0.25f),
		0.5f * (sin(time + 2.0f) + 0.25f)
	);

	ExtendList::Get(m_Sprites, 2).Draw
	(
		220.0f,
		400.0f,
		20.0f * time,
		0.3f * (sin(time + 3.0f) + 0.5f),
		0.3f * (sin(time + 3.0f) + 0.5f)
	);
}