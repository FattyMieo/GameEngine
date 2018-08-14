#pragma once
#include <vector>
#include "ParticleAffectorBase.h"
#include "GravityAffector.h"
#include "ParticleAffectorOverLifespan.h"
#include "TransparencyAffectorOverLifespan.h"
#include "ColorAffectorOverLifespan.h"

class ParticleAffectorGroup
{
private:
	std::vector<ParticleAffectorBase*> wrappedVector;

public:
	GravityAffector* gravity;
	TransparencyAffectorOverLifespan* transparencyOverLifespan;
	ColorAffectorOverLifespan* colorOverLifespan;

	ParticleAffectorGroup();
	virtual ~ParticleAffectorGroup();
	
	std::vector<ParticleAffectorBase*>& GetVector();
};
