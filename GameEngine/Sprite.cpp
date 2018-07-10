#include "Sprite.h"
#include "Drawer.h"
#include <iostream>

Sprite::Sprite()
{
	m_width = 128;
	m_height = 128;
}

Sprite::Sprite(unsigned int width, unsigned int height)
{
	SetDimension(width, height);
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

void Sprite::SetTextureID(GLuint textureID)
{
	this->m_textureID[0] = textureID;
}

void Sprite::SetDimension(unsigned int width, unsigned int height)
{
	this->m_width = width;
	this->m_height = height;
}

void Sprite::Draw()
{
	Matrix transMatrix = Matrix::makeTranslationMatrix(Vector(transform.position.x, transform.position.y, 0.0f));
	Matrix rotMatrix = Matrix::makeRotateMatrix(transform.rotation, Vector(0.0f, 0.0f, 1.0f));
	Matrix scaleMatrix = Matrix::makeScaleMatrix(Vector(transform.scale.x, transform.scale.y, 0.0f));

	Matrix viewMatrix = transMatrix * rotMatrix * scaleMatrix;

	glLoadMatrixf((GLfloat*)viewMatrix.mVal);
	Drawer::DrawSquare(m_textureID[0], 0, 0, m_width, m_height);
}

void Sprite::Draw(float x, float y, float rotation, float scaleX, float scaleY)
{
	transform.position.x = x;
	transform.position.y = y;
	transform.rotation = rotation;
	transform.scale.x = scaleX;
	transform.scale.y = scaleY;

	Draw();
}

void Sprite::Draw(Vector2 position, float rotation, Vector2 scale)
{
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	Draw();
}

void Sprite::Draw(Transform2D newTransform)
{
	transform = newTransform;

	Draw();
}