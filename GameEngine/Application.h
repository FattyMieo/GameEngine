//#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Sprite.h"

static class Application
{
private:
	static Application* m_instance;
	Sprite m_dummySprite;
public:
	Application();
	~Application();

	static Application* GetInstance();

	void Start();
	void Update(float deltaTime);
	void Draw();
};

#endif