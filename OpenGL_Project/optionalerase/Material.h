#pragma once

#include "VectorN.h"

class Material
{
public:
	Material();
	void setEmission(float r, float g, float b, float a);
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void setShininess(float sh);

	VectorN<float, 4> getEmission() const;
	VectorN<float, 4> getAmbient() const;
	VectorN<float, 4> getDiffuse() const;
	VectorN<float, 4> getSpecular() const;
	VectorN<float, 1> getShininess() const;

private:
	VectorN<float, 4> emission;
	VectorN<float, 4> ambient;
	VectorN<float, 4> diffuse;
	VectorN<float, 4> specular;
	VectorN<float, 1> shininess;
};

