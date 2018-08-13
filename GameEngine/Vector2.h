#pragma once

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);
	~Vector2();

	void SetEqual(float f);
	Vector2& operator+=(const Vector2& vec);
	Vector2& operator*(const float f);
};