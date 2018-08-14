#pragma once

template<class T>
struct ParticleAttributeRandomItem
{
	bool useRandom;
	T min;
	T max;

	ParticleAttributeRandomItem()
	{
		useRandom = false;
	}
};
