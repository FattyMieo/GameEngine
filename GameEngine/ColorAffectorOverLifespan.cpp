#include "ColorAffectorOverLifespan.h"

ColorAffectorOverLifespan::ColorAffectorOverLifespan() : ParticleAffectorOverLifespan<Color>()
{
	lifespanValue[0.0f] = Color(255);
	lifespanValue[1.0f] = Color(255);
}

ColorAffectorOverLifespan::~ColorAffectorOverLifespan()
{

}

void ColorAffectorOverLifespan::UpdateParticle(ParticleObject* particle, float deltaTime)
{
	Color a, b;
	float t;

	float t0 = particle->GetLife() / particle->GetFullLife();

	if (CalculateBounds(t0, a, b, t))
	{
		Color origColor = particle->GetSprite().GetColor();
		origColor.r = (GLubyte)MathExtension::Lerp(a.r, b.r, t);
		origColor.g = (GLubyte)MathExtension::Lerp(a.g, b.g, t);
		origColor.b = (GLubyte)MathExtension::Lerp(a.b, b.b, t);
		particle->GetSprite().SetColor(origColor);
	}
}