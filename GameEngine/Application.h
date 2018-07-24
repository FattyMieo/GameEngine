//#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <GLFW/glfw3.h>
#include "IRunnable.h"
#include "IDrawable.h"
#include "ExtendList.h"
#include "Container.h"
#include "GameObject.h"

class Application : public IRunnable, public IDrawable
{
protected:
	std::list<GameObject*> m_GameObjects;
	Container<GameObject> m_GameObjectsCon;

public:
	Application();
	virtual ~Application();

	virtual void Start();
	virtual void Update(float deltaTime);
	void Draw();

	GameObject* Instantiate();
	GameObject* Instantiate(GameObject* copy);
	GameObject* Instantiate(Transform2D transform);
	GameObject* Instantiate(Vector2 position, float rotation);
	GameObject* Instantiate(Vector2 position, float rotation, Vector2 scale);

	GameObject& FindGameObject(int index);
};

#endif