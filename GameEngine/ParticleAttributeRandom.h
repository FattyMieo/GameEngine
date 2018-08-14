#pragma once
#include "Vector2.h"
#include "Color.h"
#include "ParticleAttributeRandomItem.h"

struct ParticleAttributeRandom
{
	ParticleAttributeRandomItem<float> startDelay;
	ParticleAttributeRandomItem<float> startLifespan;
	ParticleAttributeRandomItem<Vector2> startVelocity;
	ParticleAttributeRandomItem<Vector2> startAcceleration;
	ParticleAttributeRandomItem<Vector2> startSize;
	ParticleAttributeRandomItem<float> startRotation;
	ParticleAttributeRandomItem<Color> startColor;
};