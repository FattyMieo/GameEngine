#pragma once
#include "Sprite.h"

struct ParticleAttributeEmitter
{
	Sprite emitterSprite;

	float emissionRate;
	//float emissionRateOverTime;
	//float emissionRateOverDistance;

	ParticleAttributeEmitter()
	{
		emitterSprite.LoadFromFile("../Media/BaseParticle.bmp");
		emitterSprite.SetBlendingMode(BM_Additive);
		emissionRate = 10.0f;
	}
};