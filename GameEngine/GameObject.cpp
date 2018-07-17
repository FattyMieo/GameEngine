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

Sprite& GameObject::GetSprite()
{
	return m_sprite;
}

void GameObject::SetSprite(Sprite& sprite)
{
	m_sprite = sprite;
}

void GameObject::Draw()
{
	GetSprite().Draw();
}

void GameObject::Start()
{

}

void GameObject::Update(float deltaTime)
{

}