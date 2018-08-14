#pragma once
#include "ParticleAffectorOverLifespan.h"
#include "Vector2.h"

class LimitVelocityAffectorOverLifespan : public ParticleAffectorOverLifespan<Vector2>
{
public:
	LimitVelocityAffectorOverLifespan();
	virtual ~LimitVelocityAffectorOverLifespan();

	virtual void UpdateParticle(ParticleObject* particle);
};