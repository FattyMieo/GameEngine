#include "ParticleObject.h"

ParticleObject::ParticleObject() : GameObject()
{
	GetSprite().LoadFromFile("../Media/BaseParticle.bmp");
	GetSprite().SetBlendingMode(BM_Additive);

	Initialize
	(
		Vector2(0.0f, 0.0f),
		0.0f,
		Vector2(1.0f, 1.0f),
		Vector2(0.0f, 0.0f),
		Vector2(0.0f, 0.0f)
	);
}

ParticleObject::ParticleObject(Sprite sprite, Vector2 pos, float rot, Vector2 size, Vector2 vel, Vector2 accel)
	: GameObject(sprite)
{
	GetSprite().SetBlendingMode(BM_Additive);
	Initialize(pos, rot, size, vel, accel);
}

ParticleObject::ParticleObject(Vector2 pos, float rot, Vector2 size, Vector2 vel, Vector2 accel)
	: GameObject()
{
	GetSprite().LoadFromFile("../Media/BaseParticle.bmp");
	GetSprite().SetBlendingMode(BM_Additive);
	Initialize(pos, rot, size, vel, accel);
}

ParticleObject::ParticleObject(Transform2D trans, Vector2 vel, Vector2 accel)
	: ParticleObject(trans.position, trans.rotation, trans.scale, vel, accel) { }

ParticleObject::ParticleObject(Sprite sprite, Transform2D trans, Vector2 vel, Vector2 accel)
	: ParticleObject(sprite, trans.position, trans.rotation, trans.scale, vel, accel) { }

ParticleObject::~ParticleObject() { }

void ParticleObject::Initialize(Vector2 pos, float rot, Vector2 size, Vector2 vel, Vector2 accel)
{
	GetTransform().position = pos;
	GetTransform().rotation = rot;
	GetTransform().scale = size;

	m_velocity = vel;
	m_acceleration = accel;
}

float ParticleObject::GetLife()
{
	return m_life;
}

float ParticleObject::GetFullLife()
{
	return m_fullLife;
}

void ParticleObject::SetFullLife(float fullLife)
{
	m_fullLife = fullLife;
}

Vector2 ParticleObject::GetVelocity()
{
	return m_velocity;
}

void ParticleObject::SetVelocity(Vector2 vel)
{
	m_velocity = vel;
}

Vector2 ParticleObject::GetAcceleration()
{
	return m_acceleration;
}

void ParticleObject::SetAcceleration(Vector2 accel)
{
	m_acceleration = accel;
}

void ParticleObject::Start()
{
	m_life = m_fullLife;
}

void ParticleObject::Update(float deltaTime)
{
	//Acceleration --affect--> Velocity --affect--> Position
	m_velocity += m_acceleration;
	GetTransform().position += m_velocity;

	//Decrease life of particle every update
	//m_life--; //(Doesn't affected by FPS)
	m_life -= deltaTime; //(Affected by FPS, best)
}

bool ParticleObject::DestroyNow()
{
	return m_life <= 0.0f;
}
