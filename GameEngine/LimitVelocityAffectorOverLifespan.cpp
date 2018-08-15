#include "LimitVelocityAffectorOverLifespan.h"

LimitVelocityAffectorOverLifespan::LimitVelocityAffectorOverLifespan() : ParticleAffectorOverLifespan<Vector2>()
{
	lifespanValue[0.0f] = Vector2(1.0f);
	lifespanValue[1.0f] = Vector2(1.0f);
}

LimitVelocityAffectorOverLifespan::~LimitVelocityAffectorOverLifespan()
{

}

void LimitVelocityAffectorOverLifespan::UpdateParticle(ParticleObject* particle, float deltaTime)
{
	Vector2 a, b;
	float t;

	float t0 = particle->GetLife() / particle->GetFullLife();

	if (CalculateBounds(t0, a, b, t))
	{
		Vector2 limit = Vector2::Lerp(a, b, t);
		Vector2 pVel = particle->GetVelocity();

		if (pVel.x > limit.x)
		{
			pVel.x = limit.x;
		}

		if (pVel.y > limit.y)
		{
			pVel.y = limit.y;
		}

		particle->SetVelocity(pVel);
	}
}