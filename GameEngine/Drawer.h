#pragma once

#include <GLFW/glfw3.h>

static class Drawer
{
public:
	static void DrawSquare(GLuint textureID, int x, int y, int width, int height);
};