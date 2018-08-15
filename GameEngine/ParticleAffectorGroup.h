#pragma once
#include <vector>
#include "ParticleAffectorBase.h"
#include "GravityAffector.h"
#include "ParticleAffectorOverLifespan.h"
#include "TransparencyAffectorOverLifespan.h"
#include "ColorAffectorOverLifespan.h"
#include "SizeAffectorOverLifespan.h"
#include "RotationAffectorOverLifespan.h"
#include "LimitVelocityAffectorOverLifespan.h"
#include "AnimationAffector.h"

class ParticleAffectorGroup
{
private:
	std::vector<ParticleAffectorBase*> wrappedVector;

public:
	GravityAffector* gravity;
	AnimationAffector* animation;
	TransparencyAffectorOverLifespan* transparencyOverLifespan;
	ColorAffectorOverLifespan* colorOverLifespan;
	SizeAffectorOverLifespan* sizeOverLifespan;
	RotationAffectorOverLifespan* rotationOverLifespan;
	LimitVelocityAffectorOverLifespan* limitVelocityOverLifespan;

	ParticleAffectorGroup();
	virtual ~ParticleAffectorGroup();
	
	std::vector<ParticleAffectorBase*>& GetVector();
};
