#include "Color.h"

Color::Color()
{
	r = 255;
	g = 255;
	b = 255;
	a = 255;
}

Color::Color(GLubyte c, GLubyte a)
{
	this->r = c;
	this->g = c;
	this->b = c;
	this->a = a;
}

Color::Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color Color::Lerp(Color a, Color b, float t)
{
	Color ret;
	ret.r = (GLubyte)((1.0f - t) * a.r + t * b.r);
	ret.g = (GLubyte)((1.0f - t) * a.g + t * b.g);
	ret.b = (GLubyte)((1.0f - t) * a.b + t * b.b);
	ret.a = (GLubyte)((1.0f - t) * a.a + t * b.a);

	return ret;
}

Color Color::Random(Color a, Color b)
{
	Color ret;
	ret.r = (GLubyte)MathExtension::GetRandomInt(a.r, b.r);
	ret.g = (GLubyte)MathExtension::GetRandomInt(a.g, b.g);
	ret.b = (GLubyte)MathExtension::GetRandomInt(a.b, b.b);
	ret.a = (GLubyte)MathExtension::GetRandomInt(a.a, b.a);

	return ret;
}
