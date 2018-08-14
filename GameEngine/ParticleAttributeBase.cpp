#include "ParticleAttributeBase.h"

ParticleAttributeBase::ParticleAttributeBase()
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

float ParticleAttributeBase::GetStartDelay()
{
	ParticleAttributeRandomItem<float> item = random.startDelay;

	if (!item.useRandom)
	{
		return startDelay;
	}
	else
	{
		return startDelay + MathExtension::GetRandomFloat(item.min, item.max);
	}
}

float ParticleAttributeBase::GetStartLifespan()
{
	ParticleAttributeRandomItem<float> item = random.startLifespan;

	if (!item.useRandom)
	{
		return startLifespan;
	}
	else
	{
		return startLifespan + MathExtension::GetRandomFloat(item.min, item.max);
	}
}

Vector2 ParticleAttributeBase::GetStartVelocity()
{
	ParticleAttributeRandomItem<Vector2> item = random.startVelocity;

	if (!item.useRandom)
	{
		return startVelocity;
	}
	else
	{
		return startVelocity + Vector2::Random(item.min, item.max);
	}
}

Vector2 ParticleAttributeBase::GetStartAcceleration()
{
	ParticleAttributeRandomItem<Vector2> item = random.startAcceleration;

	if (!item.useRandom)
	{
		return startAcceleration;
	}
	else
	{
		return startAcceleration + Vector2::Random(item.min, item.max);
	}
}

Vector2 ParticleAttributeBase::GetStartSize()
{
	ParticleAttributeRandomItem<Vector2> item = random.startSize;

	if (!item.useRandom)
	{
		return startSize;
	}
	else
	{
		return startSize + Vector2::Random(item.min, item.max);
	}
}

float ParticleAttributeBase::GetStartRotation()
{
	ParticleAttributeRandomItem<float> item = random.startRotation;

	if (!item.useRandom)
	{
		return startRotation;
	}
	else
	{
		return startRotation + MathExtension::GetRandomFloat(item.min, item.max);
	}
}

Color ParticleAttributeBase::GetStartColor()
{
	ParticleAttributeRandomItem<Color> item = random.startColor;

	if (!item.useRandom)
	{
		return startColor;
	}
	else
	{
		return Color::Random(item.min, item.max);
	}
}
