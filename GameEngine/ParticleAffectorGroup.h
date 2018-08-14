#pragma once
#include <vector>
#include "ParticleAffectorBase.h"
#include "GravityAffector.h"
#include "RandomColorAffector.h"

class ParticleAffectorGroup
{
private:
	std::vector<ParticleAffectorBase*> wrappedVector;

public:
	GravityAffector* gravity;
	RandomColorAffector* randColor;

	ParticleAffectorGroup();
	virtual ~ParticleAffectorGroup();
	
	std::vector<ParticleAffectorBase*>& GetVector();
};
