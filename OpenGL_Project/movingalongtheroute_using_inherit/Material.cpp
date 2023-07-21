#include "Material.h"

Material::Material(){}
void Material::setEmission(float r, float g, float b, float a) { emission.setPos(r, g, b, a); }
void Material::setAmbient(float r, float g, float b, float a){ ambient.setPos(r, g, b, a); }
void Material::setDiffuse(float r, float g, float b, float a){ diffuse.setPos(r, g, b, a); }
void Material::setSpecular(float r, float g, float b, float a){ specular.setPos(r, g, b, a); }
void Material::setShininess(float sh) { shininess[0] = sh; }
Vector4f Material::getEmission() const { return emission; }
Vector4f Material::getAmbient() const { return ambient; }
Vector4f Material::getDiffuse() const { return diffuse; }
Vector4f Material::getSpecular() const { return specular; }
const float* Material::getShininess()const{ return shininess; }