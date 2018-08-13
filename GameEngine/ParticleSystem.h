#pragma once

#include "GameObject.h"
#include "Container.h"
#include "ParticleObject.h"
#include "ParticleAttributeBase.h"

class ParticleSystem : public GameObject
{
protected:
	//Add other ParticleAffectors
	Container<ParticleObject> m_particles;
	unsigned int particleCount;

	ParticleAttributeBase m_attributes;
	float systemTime;
	float emissionTimer;

	Vector2 gravity;
	
public:
	ParticleSystem();
	virtual ~ParticleSystem();

	Container<ParticleObject> GetParticles();
	ParticleAttributeBase& GetAttributes();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Draw();
};
