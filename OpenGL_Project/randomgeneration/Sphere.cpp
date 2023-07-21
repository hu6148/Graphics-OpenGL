#include "Sphere.h"

Sphere::Sphere() {}
Sphere::Sphere(float r, int sl, int st):radius(r),slice(sl),stack(st) {}
void Sphere::setRadius(float r) { radius = r; }
float Sphere::getRadius() const { return radius; }
void Sphere::setSlice(int sl) { slice = sl; }
void Sphere::setStack(int st) { stack = st; }
void Sphere::setLoopPointIdx(int idx) { loopPtIdx = idx; }
int Sphere::getLoopPointIdx() const { return loopPtIdx; }

void Sphere::draw() {
	glPushMatrix();

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, &(emission[0]));
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(ambient[0]));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(diffuse[0]));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(specular[0]));
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(radius, slice, stack);
	glPopMatrix();
}
