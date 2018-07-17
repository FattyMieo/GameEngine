#pragma once

#include "IRunnable.h"
#include "IDrawable.h"
#include "ExtendList.h"
#include "Component.h"
#include "Sprite.h"
#include "BlendMode.h"
#include "Transform2D.h"

class GameObject : public IRunnable, public IDrawable
{
private:
	//std::list<Component> components;

	Transform2D m_transform;
	Sprite m_sprite;
	BlendMode m_blendMode;
	//Color m_color; //Vector4

public:
	
	GameObject();
	GameObject(Sprite& sprite);
	~GameObject();

	void SetTransform(Transform2D m_transform);
	Transform2D GetTransform();

	void SetSprite(Sprite& sprite);
	Sprite& GetSprite();

	//void SetColor(const Color& color);
	//const Color& GetColor();

	void SetBlendingMode(BlendMode blend);
	BlendMode GetBlendingMode();

	virtual void Draw();
	virtual void Start();
	virtual void Update(float deltaTime);
};