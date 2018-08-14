#include "RotationAffectorOverLifespan.h"

RotationAffectorOverLifespan::RotationAffectorOverLifespan() : ParticleAffectorOverLifespan<float>()
{
	lifespanValue[0.0f] = 0.0f;
	lifespanValue[1.0f] = 0.0f;
}

RotationAffectorOverLifespan::~RotationAffectorOverLifespan()
{

}

void RotationAffectorOverLifespan::UpdateParticle(ParticleObject* particle)
{
	float a, b;
	float t;

	float t0 = particle->GetLife() / particle->GetFullLife();

	if (CalculateBounds(t0, a, b, t))
	{
		particle->GetTransform().rotation = MathExtension::Lerp(a, b, t);
	}
}