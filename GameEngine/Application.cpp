#include "Application.h"
#include <iostream>

Application::Application()
{

}

Application::~Application()
{

}

void Application::InitFMOD(FMOD::System* fmodSystem)
{
	m_fmodSystem = fmodSystem;
}

void Application::Start()
{
	//std::cout << "Application Started" << std::endl;
}

void Application::Update(float deltaTime)
{
	//std::cout << "Application Updated" << std::endl;

	std::list<GameObject*>::iterator it = m_GameObjects.GetList().begin();

	while (it != m_GameObjects.GetList().end())
	{
		GameObject* go = *it;
		if (go->IsActive())
			go->Update(deltaTime);
		++it;
	}
}

void Application::OnKeyDown(GLFWwindow* window)
{
	//std::cout << "Application Key Down" << std::endl;
}

void Application::Draw()
{
	//std::cout << "Application Drawn" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::list<GameObject*>::iterator it = m_GameObjects.GetList().begin();

	while (it != m_GameObjects.GetList().end())
	{
		GameObject* go = *it;
		if(go->IsActive())
			go->Draw();
		++it;
	}
}

GameObject* Application::Instantiate()
{
	return Instantiate(new GameObject());
}

GameObject* Application::Instantiate(GameObject* copy)
{
	m_GameObjects.GetList().push_back(copy);
	copy->Start();
	return copy;
}

GameObject* Application::Instantiate(Transform2D transform)
{
	GameObject* go = new GameObject();
	go->SetTransform(transform);

	return Instantiate(go);
}

GameObject* Application::Instantiate(Vector2 position, float rotation)
{
	return Instantiate(position, rotation, Vector2(1.0f, 1.0f));
}

GameObject* Application::Instantiate(Vector2 position, float rotation, Vector2 scale)
{
	Transform2D transform;
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	return Instantiate(transform);
}

GameObject& Application::FindGameObject(int index)
{
	return m_GameObjects.GetItem(index);
}

void Application::Destroy(GameObject* gameObject)
{
	GameObject* cachedGO = gameObject;
	m_GameObjects.GetList().remove(gameObject);
	delete gameObject;
}
