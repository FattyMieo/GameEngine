//#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <GLFW/glfw3.h>
#include "Transform2D.h"
#include <cmath>

class Sprite
{
private:
	GLuint m_textureID[1];
	unsigned int m_width;
	unsigned int m_height;

public:
	Transform2D transform;

	Sprite();
	Sprite(unsigned int width, unsigned int height);
	Sprite(const std::string& file);
	~Sprite();

	void LoadFromFile(const std::string& file);
	void SetTextureID(GLuint textureID);
	void SetDimension(unsigned int width, unsigned int height);
	void Draw();
	void Draw(float x, float y, float rotation, float scaleX, float scaleY);
	void Draw(Vector2 position, float rotation, Vector2 scale);
	void Draw(Transform2D newTransform);
};

#endif
