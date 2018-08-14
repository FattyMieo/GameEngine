#include "SizeAffectorOverLifespan.h"

SizeAffectorOverLifespan::SizeAffectorOverLifespan() : ParticleAffectorOverLifespan<Vector2>()
{
	lifespanValue[0.0f] = Vector2(1.0f);
	lifespanValue[1.0f] = Vector2(1.0f);
}

SizeAffectorOverLifespan::~SizeAffectorOverLifespan()
{

}

void SizeAffectorOverLifespan::UpdateParticle(ParticleObject* particle)
{
	Vector2 a, b;
	float t;

	float t0 = particle->GetLife() / particle->GetFullLife();

	if (CalculateBounds(t0, a, b, t))
	{
		particle->GetTransform().scale = Vector2::Lerp(a, b, t);
	}
}