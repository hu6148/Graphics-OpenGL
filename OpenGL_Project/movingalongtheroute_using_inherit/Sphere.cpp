#include "Sphere.h"
#include "Constants.h"

Sphere::Sphere(){}
Sphere::Sphere(float r, int sl, int st):radius(r), slice(sl), stack(st){}
void Sphere::setRadius(float r) { radius = r; }
float Sphere::getRadius() const { return radius; }
void Sphere::setSlice(int sl) { slice = sl; }
void Sphere::setStack(int st) { stack = st; }
void  Sphere::setLoopPointIdx(int idx) { loopPtIdx = idx; }
int  Sphere::getLoopPointIdx() const { return loopPtIdx; }
void Sphere::draw() const{
	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.getEmission().getPos());
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.getAmbient().getPos());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.getDiffuse().getPos());
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.getSpecular().getPos());
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.getShininess());

	glPushMatrix();
	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(radius, slice, stack);
	glPopMatrix();
}
