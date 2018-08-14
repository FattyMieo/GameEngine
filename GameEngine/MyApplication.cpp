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
	pSys->GetTransform().position = Vector2(320.0f, 0.0f);
	pSys->GetEmitterAttributes().emissionRate = 250.0f;
	pSys->GetBaseAttributes().startSize.SetEqual(0.15f);

	pSys->GetAffectors().gravity->value = Vector2(0.0f, -0.05f);
	pSys->GetAffectors().gravity->SetActive(true);

	pSys->GetBaseAttributes().random.startVelocity.min = Vector2(-0.5f, 0.25f);
	pSys->GetBaseAttributes().random.startVelocity.max = Vector2(0.5f, 0.5f);
	pSys->GetBaseAttributes().random.startVelocity.useRandom = true;

	pSys->GetBaseAttributes().random.startColor.min = Color(64, 255);
	pSys->GetBaseAttributes().random.startColor.max = Color(255, 255);
	pSys->GetBaseAttributes().random.startColor.useRandom = true;

	pSys->GetBaseAttributes().startLifespan = 1.5f;

	pSys->GetBaseAttributes().random.startLifespan.min = -0.25f;
	pSys->GetBaseAttributes().random.startLifespan.max = 0.25f;
	pSys->GetBaseAttributes().random.startLifespan.useRandom = true;

	pSys->GetAffectors().transparencyOverLifespan->lifespanValue[0.0f] = 0;
	pSys->GetAffectors().transparencyOverLifespan->lifespanValue[0.5f] = 255;
	pSys->GetAffectors().transparencyOverLifespan->lifespanValue[1.0f] = 128;
	pSys->GetAffectors().transparencyOverLifespan->SetActive(true);

	pSys->GetAffectors().colorOverLifespan->lifespanValue[0.0f] = Color(255, 0, 0);
	pSys->GetAffectors().colorOverLifespan->lifespanValue[0.25f] = Color(255, 0, 0);
	pSys->GetAffectors().colorOverLifespan->lifespanValue[0.75f] = Color(255, 255, 0);
	pSys->GetAffectors().colorOverLifespan->lifespanValue[1.0f] = Color(0, 255, 255);
	pSys->GetAffectors().colorOverLifespan->SetActive(true);

	pSys->GetAffectors().sizeOverLifespan->lifespanValue[0.0f] = Vector2(0.1f, 1.0f);
	pSys->GetAffectors().sizeOverLifespan->lifespanValue[0.75f] = Vector2(0.5f, pSys->GetBaseAttributes().GetStartSize().y * 2.0f);
	pSys->GetAffectors().sizeOverLifespan->lifespanValue[1.0f] = pSys->GetBaseAttributes().GetStartSize();
	pSys->GetAffectors().sizeOverLifespan->SetActive(true);
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

	//Stress Test
	//GameObject* go = Instantiate();
	//std::cout << go->name << std::endl;
	//Destroy(go);
}