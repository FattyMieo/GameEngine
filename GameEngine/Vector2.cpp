#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{

}

void Vector2::SetEqual(float f)
{
	this->x = f;
	this->y = f;
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2& Vector2::operator*(const float f)
{
	this->x *= f;
	this->y *= f;
	return *this;
}
