#pragma once
#include "GameObject.h"
#include "Vector2.h"

class ParticleObject : public GameObject
{
protected:
	Vector2 m_velocity;
	Vector2 m_acceleration;
	float m_life;
	float m_fullLife;

public:
	ParticleObject();
	ParticleObject(Sprite& sprite, Vector2 pos, Vector2 vel, Vector2 accel);
	virtual ~ParticleObject();

	float GetLife(); //Get remaining life
	float GetFullLife();

	virtual void Update(float deltaTime);
};