#pragma once
#include "ParticleAffectorOverLifespan.h"

class RotationAffectorOverLifespan : public ParticleAffectorOverLifespan<float>
{
public:
	RotationAffectorOverLifespan();
	virtual ~RotationAffectorOverLifespan();

	virtual void UpdateParticle(ParticleObject* particle, float deltaTime);
};