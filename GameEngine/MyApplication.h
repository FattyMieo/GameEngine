#pragma once

#include "Application.h"

class MyApplication : public Application
{
public:
	float time;

	MyApplication();
	virtual ~MyApplication();

	void Start() override;
	void Update(float deltaTime) override;
};