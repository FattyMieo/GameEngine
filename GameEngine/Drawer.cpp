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

void Drawer::DrawGeometry(GLuint textureID, GLfloat* vertices, GLfloat* texCoords, GLubyte* colors)
{
	glEnable(GL_TEXTURE_2D); //Enable texturing
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::DrawSquare(GLuint textureID, int x, int y, int width, int height, int depth, GLubyte r, GLubyte g, GLubyte b, GLubyte a, Vector2 minUV, Vector2 maxUV)
{
	float halfWidth = (float)width / 2.0f;
	float halfHeight = (float)height / 2.0f;

	float depth_f = depth / 10.0f;

	GLfloat vertices[] =
	{
		x - halfWidth, y - halfHeight, depth_f,
		x - halfWidth, y + halfHeight, depth_f,
		x + halfWidth, y - halfHeight, depth_f,

		x - halfWidth, y + halfHeight, depth_f,
		x + halfWidth, y - halfHeight, depth_f,
		x + halfWidth, y + halfHeight, depth_f
	};

	GLfloat* texCoords = GLExtension::GetUV(minUV, maxUV);

	GLubyte colors[] =
	{
		r, g, b, a,
		r, g, b, a,
		r, g, b, a,

		r, g, b, a,
		r, g, b, a,
		r, g, b, a
	};

	DrawGeometry(textureID, vertices, texCoords, colors);
}

void Drawer::DrawSquare(GLuint textureID, int x, int y, int width, int height, int depth, GLubyte r, GLubyte g, GLubyte b, GLubyte a)
{
	DrawSquare(textureID, x, y, width, height, depth, r, g, b, a, Vector2(0.0), Vector2(1.0));
}

void Drawer::DrawSquare(GLuint textureID, int x, int y, int width, int height, int depth)
{
	DrawSquare(textureID, x, y, width, height, depth, 255, 255, 255, 255);
}