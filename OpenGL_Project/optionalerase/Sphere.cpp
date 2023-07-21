#include "Sphere.h"

Sphere::Sphere(float r, int sl, int st) : Shape3D() {
	radius = r;
	slice = sl;
	stack = st;
}

float Sphere::getRadius() const {
	return radius;
}

void Sphere::draw() const {
	glPushMatrix();

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, &mtl.getEmission()[0]);
	glMaterialfv(GL_FRONT, GL_AMBIENT, &mtl.getAmbient()[0]);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &mtl.getDiffuse()[0]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &mtl.getSpecular()[0]);
	glMaterialfv(GL_FRONT, GL_SHININESS, &mtl.getShininess()[0]);

	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(radius, slice, stack);
	glPopMatrix();
}