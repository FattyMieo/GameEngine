#include "RandomColorAffector.h"

RandomColorAffector::RandomColorAffector() : ParticleAffectorBase()
{

}

RandomColorAffector::~RandomColorAffector()
{

}

void RandomColorAffector::UpdateParticle(ParticleObject* particle)
{
	particle->GetSprite().SetColor(Color::Random(minValue, maxValue));
}