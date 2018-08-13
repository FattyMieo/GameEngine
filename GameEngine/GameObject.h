#pragma once

#include "IRunnable.h"
#include "IDrawable.h"
#include "ExtendList.h"
#include "Component.h"
#include "Transform2D.h"
#include "Sprite.h"
#include <string>

class GameObject : public IRunnable, public IDrawable
{
private:
	//Container<Component> m_Components;

	Transform2D m_transform;
	Sprite m_sprite;

public:
	std::string name;

	GameObject();
	GameObject(Sprite& sprite);
	virtual ~GameObject();

	void SetTransform(Transform2D& transform);
	Transform2D& GetTransform();

	void SetSprite(Sprite& sprite);
	Sprite& GetSprite();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Draw();
};