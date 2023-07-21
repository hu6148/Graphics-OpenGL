#pragma once
class Material
{
public:
	Material();
	void setEmission(float r, float g, float b, float a);
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void setShininess(float sh);

	float emission[4];
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float shininess[1];
};

