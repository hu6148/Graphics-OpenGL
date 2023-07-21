#include "Light.h"

Light::Light(float x, float y, float z, int L_ID) :pos{x,y,z},lightID(L_ID) {}

void Light::setAmbient(float r, float g, float b, float a) {ambient.setPos(r, g, b, a); }
void Light::setDiffuse(float r, float g, float b, float a) { diffuse.setPos(r, g, b, a); }
void Light::setSpecular(float r, float g, float b, float a) { specular.setPos(r, g, b, a); }

void Light::draw() {
	glEnable(lightID);
	glLightfv(lightID, GL_AMBIENT, ambient.getPos());
	glLightfv(lightID, GL_DIFFUSE, diffuse.getPos());
	glLightfv(lightID, GL_SPECULAR, specular.getPos());
	glLightfv(lightID, GL_POSITION, pos.getPos());
}
int Light::getID() const { return lightID; }