#include "Sprite.h"
#include "Drawer.h"
#include <iostream>

Sprite::Sprite()
{
	m_width = 128;
	m_height = 128;
}

Sprite::Sprite(const std::string& file)
{
	LoadFromFile(file);
}

Sprite::~Sprite()
{

}

void Sprite::LoadFromFile(const std::string& file)
{
	glGenTextures(1, m_textureID);
	Drawer::LoadTexture(file.c_str(), m_textureID[0], m_width, m_height);
}

void Sprite::SetTextureID(const GLuint textureID)
{
	this->m_textureID[0] = textureID;
}

void Sprite::SetColor(const Color& color)
{
	m_color = color;
}

const Color& Sprite::GetColor()
{
	return m_color;
}

void Sprite::Draw()
{
	Matrix transMatrix = Matrix::makeTranslationMatrix(Vector(m_transform.position.x, m_transform.position.y, 0.0f));
	Matrix rotMatrix = Matrix::makeRotateMatrix(m_transform.rotation, Vector(0.0f, 0.0f, 1.0f));
	Matrix scaleMatrix = Matrix::makeScaleMatrix(Vector(m_transform.scale.x, m_transform.scale.y, 0.0f));

	Matrix viewMatrix = transMatrix * rotMatrix * scaleMatrix;

	glLoadMatrixf((GLfloat*)viewMatrix.mVal);

	Drawer::DrawSquare(m_textureID[0], 0, 0, m_width, m_height, GetColor().r, GetColor().g, GetColor().b);
}

void Sprite::Draw(float x, float y, float rotation, float scaleX, float scaleY)
{
	m_transform.position.x = x;
	m_transform.position.y = y;
	m_transform.rotation = rotation;
	m_transform.scale.x = scaleX;
	m_transform.scale.y = scaleY;

	Draw();
}

void Sprite::Draw(Vector2 position, float rotation, Vector2 scale)
{
	m_transform.position = position;
	m_transform.rotation = rotation;
	m_transform.scale = scale;

	Draw();
}

void Sprite::Draw(Transform2D newTransform)
{
	m_transform = newTransform;

	Draw();
}