#pragma once
#include "Vector2.h"
#include "Color.h"
#include "MathExtension.h"
#include "ParticleAttributeRandom.h"

struct ParticleAttributeBase
{
	float duration;
	bool looping;
	unsigned int maxParticles;

	float startDelay;
	float startLifespan;
	Vector2 startVelocity;
	Vector2 startAcceleration;
	Vector2 startSize;
	float startRotation;
	Color startColor;

	ParticleAttributeRandom random;

	ParticleAttributeBase();

	float GetStartDelay();
	float GetStartLifespan();
	Vector2 GetStartVelocity();
	Vector2 GetStartAcceleration();
	Vector2 GetStartSize();
	float GetStartRotation();
	Color GetStartColor();
};
