#include "Drawer.h"

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