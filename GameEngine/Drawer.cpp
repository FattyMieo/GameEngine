#include "Drawer.h"

void Drawer::LoadTexture(const char* path, GLuint textureID, unsigned int& width, unsigned int& height)
{
	CBitmap bitmap(path);

	glBindTexture(GL_TEXTURE_2D, textureID);

	// Repeat the texture after exceeding 1.0f
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Apply texture wrapping along horizontal part
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Apply texture wrapping along vertical part

																  // Bilinear filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Near filtering (For when texture needs to scale...)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Far filtering (For when texture needs to scale...)

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.GetWidth(), bitmap.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.GetBits());

	width = bitmap.GetWidth();
	height = bitmap.GetHeight();
}

void Drawer::DrawSquare(GLuint textureID, int x, int y, int width, int height)
{
	glEnable(GL_TEXTURE_2D); //Enable texturing
	glBindTexture(GL_TEXTURE_2D, textureID);

	float halfWidth = (float)width / 2.0f;
	float halfHeight = (float)height / 2.0f;

	GLfloat vertices[] =
	{
		x - halfWidth, y - halfHeight, 0.0f,
		x - halfWidth, y + halfHeight, 0.0f,
		x + halfWidth, y - halfHeight, 0.0f,

		x - halfWidth, y + halfHeight, 0.0f,
		x + halfWidth, y - halfHeight, 0.0f,
		x + halfWidth, y + halfHeight, 0.0f
	};

	GLfloat texCoords[] =
	{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	GLubyte colors[] =
	{
		255, 255, 255,
		255, 255, 255,
		255, 255, 255,

		255, 255, 255,
		255, 255, 255,
		255, 255, 255
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}