#pragma once
#include "ParticleObject.h"

class ParticleAffectorBase
{
private:
	bool m_active;

public:
	ParticleAffectorBase();
	virtual ~ParticleAffectorBase();

	bool IsActive();
	void SetActive(bool active);

	virtual void UpdateParticle(ParticleObject* particle) = 0;
};
