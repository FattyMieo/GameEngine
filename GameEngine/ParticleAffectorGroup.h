#pragma once
#include <vector>
#include "ParticleAffectorBase.h"
#include "GravityAffector.h"

class ParticleAffectorGroup
{
private:
	std::vector<ParticleAffectorBase*> wrappedVector;

public:
	GravityAffector* gravity;

	ParticleAffectorGroup();
	virtual ~ParticleAffectorGroup();
	
	std::vector<ParticleAffectorBase*>& GetVector();
};
