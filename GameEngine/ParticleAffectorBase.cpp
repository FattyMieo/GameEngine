#include "ParticleAffectorBase.h"

ParticleAffectorBase::ParticleAffectorBase()
{
	SetActive(false);
}

ParticleAffectorBase::~ParticleAffectorBase()
{

}

bool ParticleAffectorBase::IsActive()
{
	return m_active;
}

void ParticleAffectorBase::SetActive(bool active)
{
	m_active = active;
}
