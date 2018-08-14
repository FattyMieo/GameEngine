#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() : GameObject()
{

}

ParticleSystem::~ParticleSystem()
{

}

Container<ParticleObject> ParticleSystem::GetParticles()
{
	return m_particles;
}

ParticleAttributeBase& ParticleSystem::GetBaseAttributes()
{
	return m_bAttributes;
}

ParticleAttributeEmitter& ParticleSystem::GetEmitterAttributes()
{
	return m_eAttributes;
}

ParticleAffectorGroup& ParticleSystem::GetAffectors()
{
	return m_affectors;
}

void ParticleSystem::Start()
{

}

void ParticleSystem::Update(float deltaTime)
{
	systemTime += deltaTime;

	bool canEmit = true;

	if (systemTime <= GetBaseAttributes().startDelay)
	{
		canEmit = false;
	}
	else
	{
		if (!GetBaseAttributes().looping)
		{
			if (systemTime > GetBaseAttributes().duration + GetBaseAttributes().startDelay)
			{
				canEmit = false;
			}
		}
	}

	if (canEmit)
	{
		float newEmission = deltaTime * GetEmitterAttributes().emissionRate;
		//Limiting the FPS to 60 (0.016 ms)
		if (newEmission > 0.0167f * GetEmitterAttributes().emissionRate)
		{
			newEmission = 0.0167f * GetEmitterAttributes().emissionRate;
		}

		emissionTimer += newEmission;

		while (emissionTimer >= 1.0f)
		{
			if (particleCount > GetBaseAttributes().maxParticles)
			{
				emissionTimer -= floor(emissionTimer);
				break;
			}

			emissionTimer -= 1.0f;

			ParticleObject* particle = new ParticleObject
			(
				GetEmitterAttributes().emitterSprite,
				GetTransform().position,
				GetBaseAttributes().startRotation,
				GetBaseAttributes().startSize,
				GetBaseAttributes().startVelocity,
				GetBaseAttributes().startAcceleration
			);

			particle->GetSprite().SetColor(GetBaseAttributes().startColor);
			particle->SetFullLife(GetBaseAttributes().startLifespan);

			m_particles.GetList().push_back(particle);
			particle->Start();

			++particleCount;
		}
	}

	std::list<ParticleObject*>::iterator it = m_particles.GetList().begin();
	while (it != m_particles.GetList().end())
	{
		ParticleObject* particle = *it;

		if (particle->DestroyNow())
		{
			it = m_particles.GetList().erase(it);
			--particleCount;
			delete particle;
			continue;
		}
		
		std::vector<ParticleAffectorBase*>::iterator a_it = m_affectors.GetVector().begin();
		while (a_it != m_affectors.GetVector().end())
		{
			ParticleAffectorBase* affector = *a_it;
			if (affector->IsActive())
			{
				affector->UpdateParticle(particle);
			}

			++a_it;
		}

		particle->Update(deltaTime);

		++it;
	}
}

void ParticleSystem::Draw()
{
	std::list<ParticleObject*>::iterator it = m_particles.GetList().begin();
	while (it != m_particles.GetList().end())
	{
		ParticleObject* p = *it;
		p->Draw();
		++it;
	}
}
