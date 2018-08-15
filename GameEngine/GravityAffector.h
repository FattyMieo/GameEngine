#pragma once
#include "ParticleAffectorBase.h"

class GravityAffector : public ParticleAffectorBase
{
public:
	Vector2 value;

	GravityAffector();
	virtual ~GravityAffector();

	virtual void UpdateParticle(ParticleObject* particle, float deltaTime);
};
