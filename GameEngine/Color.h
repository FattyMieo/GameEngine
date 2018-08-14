#pragma once

#include <GLFW/glfw3.h>

struct Color
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;

	Color();
	Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a);
};