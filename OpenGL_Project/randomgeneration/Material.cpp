#include "Material.h"

Material::Material(){}
void Material::setEmission(float r, float g, float b, float a) { emission.setPos(r, g, b, a); }
void Material::setAmbient(float r, float g, float b, float a) { ambient.setPos(r, g, b, a); }
void Material::setDiffuse(float r, float g, float b, float a) { diffuse.setPos(r, g, b, a); }
void Material::setSpecular(float r, float g, float b, float a) { specular.setPos(r, g, b, a); }
void Material::setShininess(float sh) { shininess = sh; }
void Material::setRandomProperties() {
	srand(time(0));
	emission.setPos((rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f);
	ambient.setPos((rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f);
	diffuse.setPos((rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f);
	specular.setPos((rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f);
	shininess = (rand() % 100) / 100.0f;
}
