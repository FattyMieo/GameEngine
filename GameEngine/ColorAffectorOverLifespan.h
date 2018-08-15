#pragma once
#include "ParticleAffectorOverLifespan.h"
#include "Color.h"

class ColorAffectorOverLifespan : public ParticleAffectorOverLifespan<Color>
{
public:
	ColorAffectorOverLifespan();
	virtual ~ColorAffectorOverLifespan();

	virtual void UpdateParticle(ParticleObject* particle, float deltaTime);
};