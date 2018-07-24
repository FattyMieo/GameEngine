#pragma once

#include <GLFW/glfw3.h>
#include "Bitmap.h"

class Drawer
{
public:
	static void LoadTexture(const char* path, GLuint textureID, unsigned int& width, unsigned int& height);
	static void DrawGeometry(GLuint textureID, GLfloat* vertices, GLfloat* texCoords, GLubyte* colors);

	static void DrawSquare(GLuint textureID, int x, int y, int width, int height, GLubyte r, GLubyte g, GLubyte b);
	static void DrawSquare(GLuint textureID, int x, int y, int width, int height);
};