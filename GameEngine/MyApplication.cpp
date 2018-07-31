#include "MyApplication.h"
#include "BlendMode.h"
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
	Sprite* sp;

	go = Instantiate(Vector2(320.0f, 240.0f), 0.0f);
	sp = &(go->GetSprite());
	sp->LoadFromFile("../Media/Cat.bmp");
	sp->SetBlendingMode(BM_Additive);
	//sp->SetRenderOrder(1);

	go = Instantiate(Vector2(100.0f, 240.0f), 0.0f);
	sp = &(go->GetSprite());
	sp->LoadFromFile("../Media/Dog.bmp");
	sp->SetBlendingMode(BM_Alpha);

	cat = Instantiate(Vector2(220.0f, 400.0f), 0.0f);
	sp = &(cat->GetSprite());
	sp->LoadFromFile("../Media/Cat.bmp");
	sp->SetBlendingMode(BM_Additive);
	sp->SetColor(Color(255, 255, 255, 128));
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

	t = cat->GetTransform();
	t.rotation = 20.0f * time;
	t.scale.SetEqual(0.3f * (sin(time + 3.0f) + 0.5f));

	cat->SetTransform(t);

	//Stress Test
	//GameObject* go = Instantiate();
	//std::cout << go->name << std::endl;
	//Destroy(go);
}