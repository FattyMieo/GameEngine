#include "MyApplication.h"
#include <iostream>

MyApplication::MyApplication() : Application()
{

}

MyApplication::~MyApplication()
{

}

void MyApplication::Start()
{
	Application::Start();

	FMOD_RESULT result;
	//Load and Set up Music
	result = m_fmodSystem->createStream("../Media/Reaper_Ultimate.ogg", FMOD_SOFTWARE, 0, &m_sound[0]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_UltimateCharging.ogg", FMOD_SOFTWARE, 0, &m_sound[1]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_UltimateReady.ogg", FMOD_SOFTWARE, 0, &m_sound[2]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_UltimateAlmostReady.ogg", FMOD_SOFTWARE, 0, &m_sound[3]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_UltimateReady1.ogg", FMOD_SOFTWARE, 0, &m_sound[4]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_UltimateCharging1.ogg", FMOD_SOFTWARE, 0, &m_sound[5]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_Hello.ogg", FMOD_SOFTWARE, 0, &m_sound[6]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_Hello1.ogg", FMOD_SOFTWARE, 0, &m_sound[7]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Reaper_Hello2.ogg", FMOD_SOFTWARE, 0, &m_sound[8]);
	FMOD_ErrorCheck(result);
	result = m_fmodSystem->createStream("../Media/Overwatch_RallyTheHeroes.ogg", FMOD_SOFTWARE, 0, &m_music);
	FMOD_ErrorCheck(result);

	//BGM Play
	result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_music, false, &m_musicChannel);
	FMOD_ErrorCheck(result);
	result = m_musicChannel->setMode(FMOD_LOOP_NORMAL);
	FMOD_ErrorCheck(result);
	result = m_musicChannel->setVolume(0.15f);
	FMOD_ErrorCheck(result);

	//Hello Play
	switch (rand() % 3)
	{
	case 0:
		result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[6], false, &m_soundChannel);
		break;
	case 1:
		result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[7], false, &m_soundChannel);
		break;
	case 2:
		result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[8], false, &m_soundChannel);
		break;
	}
	FMOD_ErrorCheck(result);

	smokePosition = Vector2(320.0f, 240.0f);
	animDuration = 3.5f;
	predelayAnimDuration = 0.5f;

	Sprite* sp;
	
	reaper = Instantiate(Vector2(320.0f, 240.0f), 0.0f);
	sp = &(reaper->GetSprite());
	sp->LoadFromFile("../Media/Reaper_Body.bmp");
	sp->SetBlendingMode(BM_Alpha);
	
	reaperLH = Instantiate(Vector2(285.0f, 255.0f), 0.0f);
	sp = &(reaperLH->GetSprite());
	sp->LoadFromFile("../Media/Reaper_LeftArm.bmp");
	sp->SetBlendingMode(BM_Alpha);
	
	reaperRH = Instantiate(Vector2(340.0f, 260.0f), 0.0f);
	sp = &(reaperRH->GetSprite());
	sp->LoadFromFile("../Media/Reaper_RightArm.bmp");
	sp->SetBlendingMode(BM_Alpha);



	ultimate = Instantiate(Vector2(320.0f, 100.0f), 0.0f);
	sp = &(ultimate->GetSprite());
	sp->LoadFromFile("../Media/ReaperDeathBlossom.bmp");
	sp->SetBlendingMode(BM_Additive);

	fire = (ParticleSystem*)Instantiate(new ParticleSystem());
	fire->GetTransform().position = Vector2(320.0f, 0.0f);
	fire->GetEmitterAttributes().emissionRate = 10.0f;
	fire->GetBaseAttributes().startSize.SetEqual(0.15f);

	fire->GetEmitterAttributes().emitterSprite = Sprite("../Media/BaseParticle_Least.bmp");

	fire->GetAffectors().gravity->value = Vector2(0.0f, -0.05f);
	fire->GetAffectors().gravity->SetActive(true);

	fire->GetBaseAttributes().random.startVelocity.min = Vector2(-1.0f, -0.25f);
	fire->GetBaseAttributes().random.startVelocity.max = Vector2(1.0f, 0.25f);
	fire->GetBaseAttributes().random.startVelocity.useRandom = true;

	fire->GetBaseAttributes().random.startColor.min = Color(64, 255);
	fire->GetBaseAttributes().random.startColor.max = Color(255, 255);
	fire->GetBaseAttributes().random.startColor.useRandom = true;

	fire->GetBaseAttributes().startLifespan = 1.0f;

	fire->GetBaseAttributes().random.startLifespan.min = -0.25f;
	fire->GetBaseAttributes().random.startLifespan.max = 0.25f;
	fire->GetBaseAttributes().random.startLifespan.useRandom = true;

	fire->GetAffectors().transparencyOverLifespan->lifespanValue[0.0f] = 0;
	fire->GetAffectors().transparencyOverLifespan->lifespanValue[0.5f] = 255;
	fire->GetAffectors().transparencyOverLifespan->lifespanValue[1.0f] = 128;
	fire->GetAffectors().transparencyOverLifespan->SetActive(true);

	fire->GetAffectors().colorOverLifespan->lifespanValue[0.0f] = Color(255, 128, 128);
	fire->GetAffectors().colorOverLifespan->lifespanValue[0.25f] = Color(255, 128, 0);
	fire->GetAffectors().colorOverLifespan->lifespanValue[0.5f] = Color(255, 255, 0);
	fire->GetAffectors().colorOverLifespan->lifespanValue[0.75f] = Color(0, 255, 255);
	fire->GetAffectors().colorOverLifespan->lifespanValue[1.0f] = Color(0, 0, 255);
	fire->GetAffectors().colorOverLifespan->SetActive(true);

	fire->GetAffectors().sizeOverLifespan->lifespanValue[0.0f] = fire->GetBaseAttributes().GetStartSize() * Vector2(1.0f, 10.0f);
	fire->GetAffectors().sizeOverLifespan->lifespanValue[0.75f] = fire->GetBaseAttributes().GetStartSize() * 5.0f;
	fire->GetAffectors().sizeOverLifespan->lifespanValue[1.0f] = fire->GetBaseAttributes().GetStartSize();
	fire->GetAffectors().sizeOverLifespan->SetActive(true);



	evilEyes = (ParticleSystem*)Instantiate(new ParticleSystem());
	evilEyes->GetTransform().position = Vector2(320.0f, 300.0f);
	evilEyes->GetEmitterAttributes().emissionRate = 10.0f;
	evilEyes->GetBaseAttributes().startSize.SetEqual(0.15f);

	evilEyes->GetEmitterAttributes().emitterSprite = Sprite("../Media/BaseParticle_Less.bmp");

	evilEyes->GetBaseAttributes().startVelocity = Vector2(0.0f);
	evilEyes->GetBaseAttributes().random.startVelocity.min = Vector2(-0.5f, 0.0f);
	evilEyes->GetBaseAttributes().random.startVelocity.max = Vector2(0.5f, 0.0f);
	evilEyes->GetBaseAttributes().random.startVelocity.useRandom = true;

	evilEyes->GetBaseAttributes().startColor = Color(64, 0, 32);

	evilEyes->GetBaseAttributes().startLifespan = 1.0f;

	evilEyes->GetAffectors().transparencyOverLifespan->lifespanValue[0.0f] = 0;
	evilEyes->GetAffectors().transparencyOverLifespan->lifespanValue[1.0f] = 255;
	evilEyes->GetAffectors().transparencyOverLifespan->SetActive(true);

	evilEyes->GetBaseAttributes().startSize = Vector2(0.05f);
	evilEyes->GetAffectors().sizeOverLifespan->lifespanValue[0.0f] = evilEyes->GetBaseAttributes().GetStartSize() * Vector2(10.0f, 1.0f);
	evilEyes->GetAffectors().sizeOverLifespan->lifespanValue[0.75f] = evilEyes->GetBaseAttributes().GetStartSize() * Vector2(5.0f, 1.0f);
	evilEyes->GetAffectors().sizeOverLifespan->lifespanValue[1.0f] = evilEyes->GetBaseAttributes().GetStartSize();
	evilEyes->GetAffectors().sizeOverLifespan->SetActive(true);



	portrait = Instantiate(Vector2(320.0f, 100.0f), 0.0f);
	sp = &(portrait->GetSprite());
	sp->LoadFromFile("../Media/ReaperPortrait_Outline.bmp");
	sp->SetBlendingMode(BM_Additive);



	smoke = (ParticleSystem*)Instantiate(new ParticleSystem());
	smoke->GetTransform().position = smokePosition;
	smoke->GetEmitterAttributes().emissionRate = 100.0f;
	smoke->GetBaseAttributes().startLifespan = 1.0f;

	smoke->GetBaseAttributes().startColor = Color(64, 0, 32);
	smoke->GetBaseAttributes().blendMode = BM_Additive;

	smoke->GetBaseAttributes().startVelocity = Vector2(0.0f, 0.0f);
	smoke->GetBaseAttributes().random.startVelocity.min = Vector2(-1.0f, -1.0f);
	smoke->GetBaseAttributes().random.startVelocity.max = Vector2(1.0f, 1.0f);
	smoke->GetBaseAttributes().random.startVelocity.useRandom = true;

	smoke->GetBaseAttributes().startRotation = 0.0f;
	smoke->GetBaseAttributes().random.startRotation.min = -180.0f;
	smoke->GetBaseAttributes().random.startRotation.max = 180.0f;
	smoke->GetBaseAttributes().random.startRotation.useRandom = true;

	smoke->GetAffectors().animation->spritesheet = new Spritesheet("../Media/Smoke_Alt.bmp", 8, 4);
	smoke->GetAffectors().animation->speed = 0.05f;
	smoke->GetAffectors().animation->SetActive(true);

	smoke->GetEmitterAttributes().emitterSprite = smoke->GetAffectors().animation->spritesheet->GetSprite(0);

	smoke->GetAffectors().transparencyOverLifespan->lifespanValue[0.0f] = 0;
	smoke->GetAffectors().transparencyOverLifespan->lifespanValue[0.5f] = 255;
	smoke->GetAffectors().transparencyOverLifespan->lifespanValue[0.75f] = 128;
	smoke->GetAffectors().transparencyOverLifespan->lifespanValue[1.0f] = 255;
	smoke->GetAffectors().transparencyOverLifespan->SetActive(true);

	smoke->GetAffectors().colorOverLifespan->lifespanValue[0.0f] = Color(32, 128, 128);
	smoke->GetAffectors().colorOverLifespan->lifespanValue[0.15f] = Color(64, 128, 128);
	smoke->GetAffectors().colorOverLifespan->lifespanValue[0.5f] = Color(64, 64, 32);
	smoke->GetAffectors().colorOverLifespan->lifespanValue[1.0f] = Color(64, 0, 32);
	smoke->GetAffectors().colorOverLifespan->SetActive(true);

	smoke->GetAffectors().sizeOverLifespan->lifespanValue[0.0f] = Vector2(0.01f, smoke->GetBaseAttributes().GetStartSize().y);
	smoke->GetAffectors().sizeOverLifespan->lifespanValue[1.0f] = smoke->GetBaseAttributes().GetStartSize();
	smoke->GetAffectors().sizeOverLifespan->SetActive(true);

	//smoke->SetActive(false);



	smokeBase = (ParticleSystem*)Instantiate(new ParticleSystem());
	smokeBase->GetTransform().position = smokePosition;
	smokeBase->GetEmitterAttributes().emissionRate = 50.0f;
	smokeBase->GetBaseAttributes().startLifespan = 2.0f;

	smokeBase->GetBaseAttributes().startColor = Color(64, 0, 32);
	smokeBase->GetBaseAttributes().blendMode = BM_Additive;

	smokeBase->GetBaseAttributes().startVelocity = Vector2(0.0f);
	smokeBase->GetBaseAttributes().random.startVelocity.min = Vector2(-2.0f, -1.0f);
	smokeBase->GetBaseAttributes().random.startVelocity.max = Vector2(2.0f, 1.0f);
	smokeBase->GetBaseAttributes().random.startVelocity.useRandom = true;

	smokeBase->GetBaseAttributes().startRotation = 0.0f;
	smokeBase->GetBaseAttributes().random.startRotation.min = -180.0f;
	smokeBase->GetBaseAttributes().random.startRotation.max = 180.0f;
	smokeBase->GetBaseAttributes().random.startRotation.useRandom = true;

	smokeBase->GetAffectors().animation->spritesheet = new Spritesheet("../Media/Smoke1.bmp", 6, 5);
	smokeBase->GetAffectors().animation->speed = 0.1f;
	smokeBase->GetAffectors().animation->SetActive(true);

	smokeBase->GetEmitterAttributes().emitterSprite = smokeBase->GetAffectors().animation->spritesheet->GetSprite(0);

	smokeBase->GetAffectors().transparencyOverLifespan->lifespanValue[0.0f] = 0;
	smokeBase->GetAffectors().transparencyOverLifespan->lifespanValue[1.0f] = 128;
	smokeBase->GetAffectors().transparencyOverLifespan->SetActive(true);

	smokeBase->GetAffectors().colorOverLifespan->lifespanValue[0.0f] = Color(32, 128, 128);
	smokeBase->GetAffectors().colorOverLifespan->lifespanValue[0.25f] = Color(64, 64, 32);
	smokeBase->GetAffectors().colorOverLifespan->lifespanValue[1.0f] = Color(64, 0, 32);
	smokeBase->GetAffectors().colorOverLifespan->SetActive(true);

	//smokeBase->SetActive(false);



	bulletSpark = (ParticleSystem*)Instantiate(new ParticleSystem());
	bulletSpark->GetTransform().position = smokePosition;
	bulletSpark->GetEmitterAttributes().emissionRate = 50.0f;

	bulletSpark->GetBaseAttributes().startLifespan = 1.5f;
	bulletSpark->GetBaseAttributes().random.startLifespan.min = -0.25f;
	bulletSpark->GetBaseAttributes().random.startLifespan.max = 0.25f;
	bulletSpark->GetBaseAttributes().random.startLifespan.useRandom = true;

	bulletSpark->GetEmitterAttributes().emitterSprite = Sprite("../Media/BulletSpark.bmp");
	
	bulletSpark->GetBaseAttributes().startColor = Color(255, 0, 128);
	bulletSpark->GetBaseAttributes().blendMode = BM_Additive;
	
	bulletSpark->GetBaseAttributes().startVelocity = Vector2(0.0f);
	bulletSpark->GetBaseAttributes().random.startVelocity.min = Vector2(0.0f, -1.0f);
	bulletSpark->GetBaseAttributes().random.startVelocity.max = Vector2(0.0f, 1.0f);
	bulletSpark->GetBaseAttributes().random.startVelocity.useRandom = true;
	
	bulletSpark->GetBaseAttributes().startRotation = 0.0f;
	bulletSpark->GetBaseAttributes().random.startRotation.min = -20.0f;
	bulletSpark->GetBaseAttributes().random.startRotation.max = 20.0f;
	bulletSpark->GetBaseAttributes().random.startRotation.useRandom = true;

	bulletSpark->GetAffectors().transparencyOverLifespan->lifespanValue[0.0f] = 0;
	bulletSpark->GetAffectors().transparencyOverLifespan->lifespanValue[0.25f] = 0;
	bulletSpark->GetAffectors().transparencyOverLifespan->lifespanValue[0.5f] = 255;
	bulletSpark->GetAffectors().transparencyOverLifespan->lifespanValue[0.75f] = 0;
	bulletSpark->GetAffectors().transparencyOverLifespan->lifespanValue[1.0f] = 0;
	bulletSpark->GetAffectors().transparencyOverLifespan->SetActive(true);
	
	bulletSpark->GetAffectors().colorOverLifespan->lifespanValue[0.0f] = Color(255, 255, 128);
	bulletSpark->GetAffectors().colorOverLifespan->lifespanValue[0.25f] = Color(255, 255, 128);
	bulletSpark->GetAffectors().colorOverLifespan->lifespanValue[0.75f] = Color(255, 0, 128);
	bulletSpark->GetAffectors().colorOverLifespan->lifespanValue[1.0f] = Color(255, 0, 255);
	bulletSpark->GetAffectors().colorOverLifespan->SetActive(true);

	bulletSpark->GetBaseAttributes().startSize = Vector2(0.15f);
	bulletSpark->GetAffectors().sizeOverLifespan->lifespanValue[0.0f] = Vector2(0.0f, 0.0f);
	bulletSpark->GetAffectors().sizeOverLifespan->lifespanValue[0.25f] = Vector2(0.0f, 0.0f);
	bulletSpark->GetAffectors().sizeOverLifespan->lifespanValue[0.5f] = bulletSpark->GetBaseAttributes().GetStartSize() * Vector2(2.0f, 0.5f);
	bulletSpark->GetAffectors().sizeOverLifespan->lifespanValue[0.75f] = bulletSpark->GetBaseAttributes().GetStartSize();
	bulletSpark->GetAffectors().sizeOverLifespan->lifespanValue[1.0f] = bulletSpark->GetBaseAttributes().GetStartSize();
	bulletSpark->GetAffectors().sizeOverLifespan->SetActive(true);
}

void MyApplication::Update(float deltaTime)
{
	Application::Update(deltaTime);

	time += deltaTime;

	if (setStart)
	{
		ultCharge = 0.0f;
		ultReady = false;
		fire->GetEmitterAttributes().emissionRate = 0.0f;

		startAnimTime = time;
		isAnimating = true;
		animTimer = 0.0f;
		predelayAnimTimer = 0.0f;
		predelayDone = false;
		flipTimer = 0.2f;
		isFlipped = !isFlipped;

		//Ultimate Play
		FMOD_RESULT result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[0], false, &m_soundChannel);
		FMOD_ErrorCheck(result);

		setStart = false;
	}

	if (isAnimating)
	{
		animTimer += deltaTime;
		predelayAnimTimer += deltaTime;
		flipTimer += deltaTime;

		if (!predelayDone)
		{
			smoke->GetEmitterAttributes().emissionRate = 0.0f;
			smokeBase->GetEmitterAttributes().emissionRate = 0.0f;
			evilEyes->GetEmitterAttributes().emissionRate = 0.0f;
			bulletSpark->GetEmitterAttributes().emissionRate = 0.0f;

			if (predelayAnimTimer >= predelayAnimDuration)
			{
				predelayDone = true;
			}
		}

		if (predelayDone)
		{
			smoke->GetEmitterAttributes().emissionRate = 100.0f;
			smokeBase->GetEmitterAttributes().emissionRate = 50.0f;
			evilEyes->GetEmitterAttributes().emissionRate = 10.0f;
			bulletSpark->GetEmitterAttributes().emissionRate = 50.0f;

			//Flip Timer
			if (flipTimer >= 0.1f)
			{
				isFlipped = !isFlipped;
				flipTimer -= 0.1f;

				reaper->GetSprite().hFlip = isFlipped;
				reaperLH->GetSprite().hFlip = isFlipped;
				reaperRH->GetSprite().hFlip = isFlipped;
			}

			//Animating Arms
			if (!isFlipped)
			{
				reaperLH->GetTransform().rotation = 70.0f * abs(sin(2.0f * (time - startAnimTime)));
				reaperRH->GetTransform().rotation = -70.0f * (abs(sin(2.0f * (time - startAnimTime))) - 0.4f);
				bulletSpark->GetBaseAttributes().startVelocity = Vector2(3.5f, 0.0f);
			}
			else
			{
				reaperRH->GetTransform().rotation = 70.0f * (abs(sin(2.0f * (time - startAnimTime))) - 0.4f);
				reaperLH->GetTransform().rotation = -70.0f * abs(sin(2.0f * (time - startAnimTime)));
				bulletSpark->GetBaseAttributes().startVelocity = Vector2(-3.5f, 0.0f);
			}

			float radius = 3.0f;
			float speed = 20.0f;

			//Should open a custom gameobject
			smoke->GetTransform().position = Vector2(smokePosition.x + 64.0f * radius * sin(time * speed), smokePosition.y + 10.0f * radius * cos(time * speed));
			smokeBase->GetTransform().position = Vector2(smokePosition.x + 64.0f * radius * sin((time - 0.1f) * speed), smokePosition.y + 10.0f * radius * cos((time - 0.1f) * speed));

		}

		//Animating Portait
		portrait->GetTransform().position.x = MathExtension::Lerp(0.0f, 320.0f, sin((time - startAnimTime) / animDuration * 4.0f));

		//If animation ends
		if (animTimer >= animDuration)
		{
			isFlipped = false;
			predelayDone = false;

			reaper->GetSprite().hFlip = isFlipped;
			reaperLH->GetSprite().hFlip = isFlipped;
			reaperRH->GetSprite().hFlip = isFlipped;

			reaperLH->GetTransform().rotation = 0.0f;
			reaperRH->GetTransform().rotation = 0.0f;

			isAnimating = false;
		}
	}
	else
	{
		smoke->GetEmitterAttributes().emissionRate = 0.0f;
		smokeBase->GetEmitterAttributes().emissionRate = 0.0f;
		evilEyes->GetEmitterAttributes().emissionRate = 0.0f;
		bulletSpark->GetEmitterAttributes().emissionRate = 0.0f;

		portrait->GetTransform().position.x = 0.0f;

		if (ultCharge < 100.0f)
		{
			ultCharge += deltaTime * 15.0f;
			fire->GetEmitterAttributes().emissionRate = 0.0f;
		}
		else
		{
			if (!ultReady)
			{
				//Ultimate Ready Play
				FMOD_RESULT result;
				switch (rand() % 3)
				{
				case 0:
					result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[2], false, &m_soundChannel);
					break;
				case 1:
					result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[4], false, &m_soundChannel);
					break;
				case 2:
					result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[5], false, &m_soundChannel);
					break;
				}
				FMOD_ErrorCheck(result);

				ultReady = true;
			}

			ultCharge = 100.0f;
			fire->GetEmitterAttributes().emissionRate = 10.0f;
		}
	}

	//Stress Test
	//GameObject* go = Instantiate();
	//std::cout << go->name << std::endl;
	//Destroy(go);
}


void MyApplication::OnKeyDown(GLFWwindow* window)
{
	if (glfwGetKey(window, 'Q'))
	{
		if (!isAnimating)
		{
			if (ultCharge >= 100.0f)
			{
				setStart = true;
			}
			else
			{
				//Ultimate Charging Play
				FMOD_RESULT result;
				switch (rand() % 2)
				{
				case 0:
					result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[1], false, &m_soundChannel);
					break;
				case 1:
					result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_sound[3], false, &m_soundChannel);
					break;
				}
				FMOD_ErrorCheck(result);
			}
		}
	}
}