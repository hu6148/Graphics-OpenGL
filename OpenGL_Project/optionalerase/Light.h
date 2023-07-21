#pragma once

#include "VectorN.h"

#include <GL/glut.h>

class Light
{
public:
	Light(float x, float y, float z, int L_ID);

	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);

	VectorN<float, 4> getAmbient() const;
	VectorN<float, 4> getDiffuse() const;
	VectorN<float, 4> getSpecular() const;
	int getID() const;

	void draw() const;

private:
	int lightID;
	VectorN<float, 3> pos;
	VectorN<float, 4> ambient;
	VectorN<float, 4> diffuse;
	VectorN<float, 4> specular;
};

