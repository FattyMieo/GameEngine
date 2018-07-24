// Transformation
// Sprite Pointer
// 

#include "GameObject.h"
#include "Application.h"

GameObject::GameObject()
{
	m_blendMode = BM_A;
}

GameObject::GameObject(Sprite& sprite)
{
	SetSprite(sprite);
}

GameObject::~GameObject()
{

}

void GameObject::SetTransform(Transform2D transform)
{
	m_transform = transform;
}

Transform2D GameObject::GetTransform()
{
	return m_transform;
}

void GameObject::SetSprite(Sprite& sprite)
{
	m_sprite = sprite;
}

Sprite& GameObject::GetSprite()
{
	return m_sprite;
}

void GameObject::SetBlendingMode(BlendMode mode)
{
	m_blendMode = mode;
}

BlendMode GameObject::GetBlendingMode()
{
	return m_blendMode;
}

void GameObject::Start()
{

}

void GameObject::Update(float deltaTime)
{

}

void GameObject::Draw()
{
	GetSprite().Draw(GetTransform());
}
