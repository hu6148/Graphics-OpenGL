#pragma once
#include <iostream>
#include <GL/glut.h>
#include <FreeImage.h>
class Texture
{
public:

	FIBITMAP* createBitMap(char const* filename);
	void generateTexture();
	void initTexture();
	void drawSquareWithTexture();

	GLuint textureID;
	GLubyte* textureData;
	int imageWidth, imageHeight;
};

