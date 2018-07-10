//#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Sprite.h"
#include <GLFW/glfw3.h>

class Application
{
private:
	Sprite m_dummySprite;
	Application();
public:
	float time;

	~Application();

	static Application& GetInstance();

	void Start();
	void Update(float deltaTime);
	void Draw();
};

#endif