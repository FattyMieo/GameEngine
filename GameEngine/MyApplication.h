#pragma once

#include "Application.h"
#include "ParticleSystem.h"

class MyApplication : public Application
{
public:
	float time;
	GameObject* cat;

	ParticleSystem* pSys;

	MyApplication();
	virtual ~MyApplication();

	void Start() override;
	void Update(float deltaTime) override;
};