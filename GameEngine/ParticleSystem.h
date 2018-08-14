#pragma once

#include "GameObject.h"
#include "Container.h"
#include "ParticleObject.h"
#include "ParticleAttributeBase.h"
#include "ParticleAttributeEmitter.h"
#include "ParticleAffectorGroup.h"

class ParticleSystem : public GameObject
{
protected:
	//ParticleAffectors (change to permanent struct is better)
	ParticleAffectorGroup m_affectors;
	Container<ParticleObject> m_particles;
	unsigned int particleCount;

	ParticleAttributeBase m_bAttributes;
	ParticleAttributeEmitter m_eAttributes;
	float systemTime;
	float emissionTimer;
	
public:
	ParticleSystem();
	virtual ~ParticleSystem();

	Container<ParticleObject> GetParticles();
	ParticleAttributeBase& GetBaseAttributes();
	ParticleAttributeEmitter& GetEmitterAttributes();

	ParticleAffectorGroup& GetAffectors();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Draw();
};
