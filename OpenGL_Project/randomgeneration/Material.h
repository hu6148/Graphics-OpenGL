#pragma once
#include <iostream>
#include <ctime>
#include "Vector4f.h"


class Material
{
public:
	Material();
	void setEmission(float r, float g, float b, float a);
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void setShininess(float sh);
	void setRandomProperties();

protected:
	Vector4f emission;
	Vector4f ambient;
	Vector4f diffuse;
	Vector4f specular;
	float shininess;
};

