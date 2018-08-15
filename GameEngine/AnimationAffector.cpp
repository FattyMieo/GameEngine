#include "AnimationAffector.h"

AnimationAffector::AnimationAffector() : ParticleAffectorBase()
{
	spritesheet = new Spritesheet();
	isSequential = true;
	speed = 0.0167f;
}

AnimationAffector::~AnimationAffector()
{

}

void AnimationAffector::UpdateParticle(ParticleObject* particle, float deltaTime)
{
	float animTime = particle->GetAnimTime();
	int animCount = particle->GetAnimCount();

	animTime += deltaTime;

	if (animTime >= speed)
	{
		animTime -= speed;

		if (isSequential)
		{
			animCount = (animCount + 1) % spritesheet->GetTotalSprites();
		}
		else
		{
			animCount = rand() % spritesheet->GetTotalSprites();
		}

		particle->SetSprite(spritesheet->GetSprite(animCount, particle->GetSprite()));
	}

	particle->SetAnimTime(animTime);
	particle->SetAnimCount(animCount);
}
