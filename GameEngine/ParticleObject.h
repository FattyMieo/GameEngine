#pragma once
#include "GameObject.h"
#include "IDestroyable.h"
#include "Vector2.h"

class ParticleObject : public GameObject, public IDestroyable
{
private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
	float m_life;
	float m_fullLife;

public:
	ParticleObject();
	ParticleObject(Vector2 pos, float rot, Vector2 scale, Vector2 vel, Vector2 accel);
	ParticleObject(Sprite& sprite, Vector2 pos, float rot, Vector2 scale, Vector2 vel, Vector2 accel);
	ParticleObject(Transform2D trans, Vector2 vel, Vector2 accel);
	ParticleObject(Sprite& sprite, Transform2D trans, Vector2 vel, Vector2 accel);
	virtual ~ParticleObject();

	void Initialize(Vector2 pos, float rot, Vector2 scale, Vector2 vel, Vector2 accel);
	float GetLife(); //Get remaining life
	float GetFullLife();
	void SetFullLife(float fullLife);
	Vector2 GetVelocity();
	void SetVelocity(Vector2 vel);
	Vector2 GetAcceleration();
	void SetAcceleration(Vector2 accel);

	virtual void Start();
	virtual void Update(float deltaTime);

	bool DestroyNow();
};