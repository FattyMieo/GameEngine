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
	Application::Start();

	GameObject* go;
	Sprite* sp;

	go = Instantiate(Vector2(320.0f, 240.0f), 0.0f);
	sp = &(go->GetSprite());
	sp->LoadFromFile("../Media/Cat.bmp");
	sp->SetBlendingMode(BM_Alpha);
	//sp->SetRenderOrder(1);

	go = Instantiate(Vector2(100.0f, 240.0f), 0.0f);
	sp = &(go->GetSprite());
	sp->LoadFromFile("../Media/Dog.bmp");
	sp->SetBlendingMode(BM_Alpha);

	cat = Instantiate(Vector2(220.0f, 400.0f), 0.0f);
	sp = &(cat->GetSprite());
	sp->LoadFromFile("../Media/Cat.bmp");
	sp->SetBlendingMode(BM_Alpha);

	pSys = (ParticleSystem*)Instantiate(new ParticleSystem());
	pSys->GetTransform().position = Vector2(320.0f, 240.0f);
	pSys->GetAttributes().startSize.SetEqual(0.1f);
	//pSys->GetAttributes().
}

void MyApplication::Update(float deltaTime)
{
	Application::Update(deltaTime);

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

	//Temp test
	float rx = (((rand() % (100 * 2)) - 100.0f) / 100.0f) * 1.0f;
	float ry = (((rand() % (100 * 2)) - 100.0f) / 100.0f) * 1.0f;
	pSys->GetAttributes().startVelocity = Vector2(rx, ry);

	pSys->GetAttributes().startColor = Color(rand() % 256, rand() % 256, rand() % 256, 255);

	//Stress Test
	//GameObject* go = Instantiate();
	//std::cout << go->name << std::endl;
	//Destroy(go);
}