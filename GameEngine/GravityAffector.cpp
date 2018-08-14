#include "GravityAffector.h"

GravityAffector::GravityAffector() : ParticleAffectorBase()
{

}

GravityAffector::~GravityAffector()
{

}

void GravityAffector::UpdateParticle(ParticleObject* particle)
{
	Vector2 curVel = particle->GetVelocity();

	curVel += value;

	particle->SetVelocity(curVel);
}
