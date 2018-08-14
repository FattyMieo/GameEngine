#include "ParticleAffectorGroup.h"

ParticleAffectorGroup::ParticleAffectorGroup()
{
	gravity = new GravityAffector();
	wrappedVector.push_back(gravity);

	randColor = new RandomColorAffector();
	wrappedVector.push_back(randColor);
}

ParticleAffectorGroup::~ParticleAffectorGroup()
{
	std::vector<ParticleAffectorBase*>::iterator it = wrappedVector.begin();
	while (it != wrappedVector.end())
	{
		ParticleAffectorBase* a = *it;
		delete a;
		++it;
	}

	wrappedVector.clear();
}

std::vector<ParticleAffectorBase*>& ParticleAffectorGroup::GetVector()
{
	return wrappedVector;
}
