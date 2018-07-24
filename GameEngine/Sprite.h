//#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <cmath>
#include <GLFW/glfw3.h>
#include "IDrawable.h"
#include "Component.h"
#include "Transform2D.h"
#include "Color.h"

class Sprite : public Component, public IDrawable
{
private:
	GLuint m_textureID[1];
	unsigned int m_width;
	unsigned int m_height;
	Transform2D m_transform;
	Color m_color;

public:

	Sprite();
	Sprite(const std::string& file);
	~Sprite();

	void LoadFromFile(const std::string& file);
	void SetTextureID(const GLuint textureID);
	void SetColor(const Color& color);
	const Color& GetColor();

	virtual void Draw();
	void Draw(float x, float y, float rotation, float scaleX, float scaleY);
	void Draw(Vector2 position, float rotation, Vector2 scale);
	void Draw(Transform2D newTransform);
};

#endif
