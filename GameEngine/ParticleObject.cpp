#include "ParticleObject.h"

ParticleObject::ParticleObject() : GameObject()
{
	m_velocity = Vector2(0.0f, 0.0f);
	m_acceleration = Vector2(0.0f, 0.0f);
}

ParticleObject::ParticleObject(Sprite& sprite, Vector2 pos, Vector2 vel, Vector2 accel) : GameObject(sprite)
{
	Transform2D trans = GetTransform();
	trans.position = pos;
	SetTransform(trans);

	m_velocity = vel;
	m_acceleration = accel;
}

ParticleObject::~ParticleObject() { }

float ParticleObject::GetLife()
{
	return m_life;
}

float ParticleObject::GetFullLife()
{
	return m_fullLife;
}

void ParticleObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	//Acceleration --affect--> Velocity --affect--> Position
	m_velocity += m_acceleration;
	m_transform.position += m_velocity;

	//Decrease life of particle every update
	m_life--; //(Doesn't affected by FPS)
	m_life -= deltaTime; //(Affected by FPS, best)
}