#include "Light.h"

Light::Light(float x, float y, float z, int LID) : pos{ x, y, z }, lightID(LID) {}

void Light::setAmbient(float r, float g, float b, float a) {
	ambient[0] = r; ambient[1] = g; ambient[2] = b; ambient[3] = a;
}
void Light::setDiffuse(float r, float g, float b, float a) {
	diffuse[0] = r; diffuse[1] = g; diffuse[2] = b; diffuse[3] = a;
}
void Light::setSpecular(float r, float g, float b, float a) {
	specular[0] = r; specular[1] = g; specular[2] = b; specular[3] = a;
}

void Light::draw() const {
		glEnable(lightID);
		glLightfv(lightID, GL_AMBIENT, ambient);
		glLightfv(lightID, GL_DIFFUSE, diffuse);
		glLightfv(lightID, GL_SPECULAR, specular);
		glLightfv(lightID, GL_POSITION, pos);
}
