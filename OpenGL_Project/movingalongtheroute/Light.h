#pragma once
#include "Vector3f.h"
#include "Vector4f.h"
#include <GL/glut.h>

class Light
{
public:
	Light(float x, float y, float z, int L_ID);
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void draw();
	int getID() const;

private:
	int lightID;
	Vector3f pos;
	Vector4f ambient;
	Vector4f diffuse;
	Vector4f specular;

};

