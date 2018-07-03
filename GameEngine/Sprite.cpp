#include "Sprite.h"
#include "Drawer.h"
#include <GLFW/glfw3.h>
#include <iostream>

Sprite::Sprite()
{
	width = 128;
	height = 128;
}

Sprite::~Sprite()
{

}

void Sprite::Draw(int x, int y)
{
	Drawer::DrawSquare(m_textureID, x, y, width, height);
}