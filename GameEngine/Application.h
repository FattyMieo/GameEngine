//#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <GLFW/glfw3.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include "FMODExtension.h"
#include "IRunnable.h"
#include "IDrawable.h"
#include "Container.h"
#include "GameObject.h"

class Application : public IRunnable, public IDrawable
{
protected:
	FMOD::System* m_fmodSystem;
	Container<GameObject> m_GameObjects;

public:
	Application();
	virtual ~Application();

	void InitFMOD(FMOD::System* fmodSystem);

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void OnKeyDown(GLFWwindow* window);
	void Draw();

	GameObject* Instantiate();
	GameObject* Instantiate(GameObject* copy);
	GameObject* Instantiate(Transform2D transform);
	GameObject* Instantiate(Vector2 position, float rotation);
	GameObject* Instantiate(Vector2 position, float rotation, Vector2 scale);

	GameObject& FindGameObject(int index);

	void Destroy(GameObject* gameObject);
};

#endif