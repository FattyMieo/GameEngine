//#pragma once
#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
private:
	unsigned int m_textureID;
	unsigned int width;
	unsigned int height;
public:
	Sprite();
	//Sprite(const std::strng& file);
	~Sprite();

	void Draw(int x, int y);
};

#endif
