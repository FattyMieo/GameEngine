#include "MyApplication.h"
#include <iostream>

MyApplication::MyApplication() : Application()
{

}

MyApplication::~MyApplication()
{

}

void MyApplication::Start()
{
	GameObject* go;

	go = Instantiate(Vector2(320.0f, 240.0f), 0.0f);
	go->GetSprite().LoadFromFile("../Media/Cat.bmp");

	go = Instantiate(Vector2(100.0f, 240.0f), 0.0f);
	go->GetSprite().LoadFromFile("../Media/Dog.bmp");

	go = Instantiate(Vector2(220.0f, 400.0f), 0.0f);
	go->GetSprite().LoadFromFile("../Media/Cat.bmp");
}

void MyApplication::Update(float deltaTime)
{
	time += deltaTime;

	Transform2D t;
	t = FindGameObject(0).GetTransform();
	t.rotation = 100.0f * time;
	t.scale.SetEqual(0.25f * (sin(time + 1.0f) + 1.0f));

	FindGameObject(0).SetTransform(t);

	t = FindGameObject(1).GetTransform();
	t.rotation = -15.0f * time;
	t.scale.SetEqual(0.5f * (sin(time + 2.0f) + 0.25f));

	FindGameObject(1).SetTransform(t);

	t = FindGameObject(2).GetTransform();
	t.rotation = 20.0f * time;
	t.scale.SetEqual(0.3f * (sin(time + 3.0f) + 0.5f));

	FindGameObject(2).SetTransform(t);
}