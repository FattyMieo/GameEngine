#include "TransparencyAffectorOverLifespan.h"

TransparencyAffectorOverLifespan::TransparencyAffectorOverLifespan() : ParticleAffectorOverLifespan<unsigned int>()
{
	lifespanValue[0.0f] = 255;
	lifespanValue[1.0f] = 255;
}

TransparencyAffectorOverLifespan::~TransparencyAffectorOverLifespan()
{

}

void TransparencyAffectorOverLifespan::UpdateParticle(ParticleObject* particle)
{
	unsigned int a, b;
	float t;

	float t0 = particle->GetLife() / particle->GetFullLife();

	if (CalculateBounds(t0, a, b, t))
	{
		Color origColor = particle->GetSprite().GetColor();
		origColor.a = (GLubyte)MathExtension::Lerp((int)a, (int)b, t);
		particle->GetSprite().SetColor(origColor);
	}
}