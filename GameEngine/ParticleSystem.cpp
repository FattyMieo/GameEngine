#include "ParticleSystem.h"
#include <iostream>

ParticleSystem::ParticleSystem() : GameObject()
{

}

ParticleSystem::~ParticleSystem() { }

Container<ParticleObject> ParticleSystem::GetParticles()
{
	return m_particles;
}

ParticleAttributeBase& ParticleSystem::GetAttributes()
{
	return m_attributes;
}

void RestartSystem()
{
	
}

void ParticleSystem::Start()
{

}

void ParticleSystem::Update(float deltaTime)
{
	systemTime += deltaTime;

	bool canEmit = true;

	if (systemTime <= GetAttributes().startDelay)
	{
		canEmit = false;
	}
	else
	{
		if (!GetAttributes().looping)
		{
			if (systemTime > GetAttributes().duration + GetAttributes().startDelay)
			{
				canEmit = false;
			}
		}
	}

	if (canEmit)
	{
		float newEmission = deltaTime * GetAttributes().emissionRate;
		//Limiting the FPS to 60 (0.016 ms)
		if (newEmission > 0.0167f * GetAttributes().emissionRate)
		{
			newEmission = 0.0167f * GetAttributes().emissionRate;
		}

		emissionTimer += newEmission;

		while (emissionTimer >= 1.0f)
		{
			if (particleCount > GetAttributes().maxParticles)
			{
				emissionTimer -= floor(emissionTimer);
				break;
			}

			emissionTimer -= 1.0f;

			ParticleObject* particle = new ParticleObject
			(
				GetTransform().position,
				GetAttributes().startRotation,
				GetAttributes().startSize,
				GetAttributes().startVelocity,
				GetAttributes().startAcceleration
			);

			particle->GetSprite().SetColor(GetAttributes().startColor);
			particle->SetFullLife(GetAttributes().startLifespan);

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

		if (GetAttributes().simulatedGlobally)
		{
			//particle->GetTransform().position = localPos + this->GetTransform().position;
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
