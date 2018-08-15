#include "ParticleAffectorGroup.h"

ParticleAffectorGroup::ParticleAffectorGroup()
{
	gravity = new GravityAffector();
	wrappedVector.push_back(gravity);

	transparencyOverLifespan = new TransparencyAffectorOverLifespan();
	wrappedVector.push_back(transparencyOverLifespan);

	colorOverLifespan = new ColorAffectorOverLifespan();
	wrappedVector.push_back(colorOverLifespan);

	sizeOverLifespan = new SizeAffectorOverLifespan();
	wrappedVector.push_back(sizeOverLifespan);

	rotationOverLifespan = new RotationAffectorOverLifespan();
	wrappedVector.push_back(rotationOverLifespan);

	limitVelocityOverLifespan = new LimitVelocityAffectorOverLifespan();
	wrappedVector.push_back(limitVelocityOverLifespan);


	//Place this at the last for it to update lastly
	animation = new AnimationAffector();
	wrappedVector.push_back(animation);
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
