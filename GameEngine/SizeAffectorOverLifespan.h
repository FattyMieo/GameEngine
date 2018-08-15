#pragma once
#include "ParticleAffectorOverLifespan.h"
#include "Vector2.h"

class SizeAffectorOverLifespan : public ParticleAffectorOverLifespan<Vector2>
{
public:
	SizeAffectorOverLifespan();
	virtual ~SizeAffectorOverLifespan();

	virtual void UpdateParticle(ParticleObject* particle, float deltaTime);
};