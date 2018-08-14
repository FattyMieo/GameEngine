#pragma once
#include "ParticleAffectorBase.h"
#include <map>

template<class T>
class ParticleAffectorOverLifespan : public ParticleAffectorBase
{
public:
	//Usage: lifespanValue[normalized_lifespan]
	std::map<float, T> lifespanValue;

	ParticleAffectorOverLifespan() : ParticleAffectorBase() { }
	virtual ~ParticleAffectorOverLifespan() { }

	virtual bool CalculateBounds(float t, T& a, T& b)
	{
		std::map<float, T>::iterator it = lifespanValue.begin();

		if (it == lifespanValue.end())
		{
			return false;
		}

		float upperLifespanBound = 1.0f;
		float lowerLifespanBound = 0.0f;

		while (it != lifespanValue.end())
		{
			if (it->first < upperLifespanBound && it->first >= t)
			{
				upperLifespanBound = it->first;
			}

			if (it->first > lowerLifespanBound && it->first <= t)
			{
				lowerLifespanBound = it->first;
			}

			++it;
		}

		a = lifespanValue[upperLifespanBound];
		b = lifespanValue[lowerLifespanBound];

		return true;
	}
};
