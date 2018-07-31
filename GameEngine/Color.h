#pragma once

#include <GLFW/glfw3.h>

struct Color
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;

	Color()
	{
		r = 255;
		g = 255;
		b = 255;
		a = 255;
	}

	Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};