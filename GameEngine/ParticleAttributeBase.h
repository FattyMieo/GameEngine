#pragma once
#include "Vector2.h"
#include "Color.h"

struct ParticleAttributeBase
{
	float duration;
	bool looping;
	unsigned int maxParticles;

	float startDelay;
	float startLifespan;
	Vector2 startVelocity;
	Vector2 startAcceleration; //Gravity
	Vector2 startSize;
	float startRotation;
	Color startColor;


	ParticleAttributeBase()
	{
		//Default settings
		duration = 5.0f;
		looping = true;
		startDelay = 0.0f;
		startLifespan = 5.0f;
		startVelocity = Vector2(0.0f, 5.0f);
		startAcceleration = Vector2(0.0f, 0.0f);
		startSize = Vector2(1.0f, 1.0f);
		startRotation = 0.0f;
		startColor = Color(255, 255, 255, 255);
		maxParticles = 1000;
	}
};
