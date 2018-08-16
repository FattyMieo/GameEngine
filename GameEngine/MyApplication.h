#pragma once

#include "Application.h"
#include "ParticleSystem.h"
#include "Spritesheet.h"

class MyApplication : public Application
{
public:
	float time;
	float flipTimer;
	bool isFlipped;

	bool setStart;
	float startAnimTime;
	bool isAnimating;
	float animTimer;
	float animDuration;
	float predelayAnimTimer;
	float predelayAnimDuration;
	bool predelayDone;

	float ultCharge;
	bool ultReady;

	GameObject* portrait;
	GameObject* ultimate;
	GameObject* reaper;
	GameObject* reaperLH;
	GameObject* reaperRH;

	ParticleSystem* fire;
	ParticleSystem* smoke;
	ParticleSystem* smokeBase;
	ParticleSystem* bulletSpark;
	ParticleSystem* evilEyes;

	Vector2 smokePosition;

	FMOD::Sound* m_sound[3];
	FMOD::Channel* m_soundChannel;

	FMOD::Sound* m_music;
	FMOD::Channel* m_musicChannel;

	MyApplication();
	virtual ~MyApplication();

	void Start() override;
	void Update(float deltaTime) override;
	void OnKeyDown(GLFWwindow* window) override;
};