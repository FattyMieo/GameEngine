//#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <GLFW/glfw3.h>
#include "IRunnable.h"
#include "IDrawable.h"
#include "ExtendList.h"
#include "Sprite.h"

class Application : public IRunnable, public IDrawable
{
private:
	std::list<Sprite> m_Sprites;
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