#pragma once
#include "ParticleAffectorBase.h"

class RandomColorAffector : public ParticleAffectorBase
{
public:
	Color minValue;
	Color maxValue;

	RandomColorAffector();
	virtual ~RandomColorAffector();

	virtual void UpdateParticle(ParticleObject* particle);
};
