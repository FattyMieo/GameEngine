#pragma once
#include "ParticleAffectorBase.h"
#include "Spritesheet.h"

class AnimationAffector : public ParticleAffectorBase
{
public:
	Spritesheet* spritesheet;
	bool isSequential;
	float speed;

	AnimationAffector();
	virtual ~AnimationAffector();

	virtual void UpdateParticle(ParticleObject* particle, float deltaTime);
};
