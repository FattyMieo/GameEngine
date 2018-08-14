#pragma once
#include <vector>
#include "ParticleAffectorBase.h"
#include "GravityAffector.h"
#include "ParticleAffectorOverLifespan.h"
#include "TransparencyAffectorOverLifespan.h"

class ParticleAffectorGroup
{
private:
	std::vector<ParticleAffectorBase*> wrappedVector;

public:
	GravityAffector* gravity;
	TransparencyAffectorOverLifespan* transparencyOverLifespan;

	ParticleAffectorGroup();
	virtual ~ParticleAffectorGroup();
	
	std::vector<ParticleAffectorBase*>& GetVector();
};
