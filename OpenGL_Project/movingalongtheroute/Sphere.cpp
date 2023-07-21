#include "Sphere.h"
#include "Constants.h"

Sphere::Sphere(){}
Sphere::Sphere(float r, int sl, int st): radius(r), slice(sl), stack(st) {}
void Sphere::setRadius(float r) { radius = r; }
float Sphere::getRadius() const { return radius; }
void Sphere::setSlice(int sl) { slice = sl; }
void Sphere::setStack(int st) { stack = st; }
void Sphere::setCenter(float x, float y, float z) { center.setPos(x, y, z); }
void Sphere::setCenter(const Vector3f& cen) { center.setPos(cen[0], cen[1], cen[2]); }
Vector3f Sphere::getCenter() const { return center; }
void Sphere::setVelocity(float x, float y, float z) { velocity.setPos(x, y, z); }
void Sphere::setVelocity(const Vector3f& vel) { velocity.setPos(vel[0], vel[1], vel[2]); }
Vector3f Sphere::getVelocity() const { return velocity; }
void Sphere::setLoopPointIdx(int idx) { loopPointIdx = idx; }
int Sphere::getLoopPointIdx() const { return loopPointIdx; }
void Sphere::move(){
	if (center[0] + radius >= WINDOW_WIDTH / 2 || center[0] - radius <= -(WINDOW_WIDTH / 2))
		velocity[0] = -velocity[0];
	if (center[1] + radius >= WINDOW_HEIGHT / 2 || center[1] - radius <= -(WINDOW_HEIGHT / 2))
		velocity[1] = -velocity[1];
	center[0] += velocity[0];
	center[1] += velocity[1];
	center[2] += velocity[2];
}
void Sphere::setMTL(const Material& m) { mtl = m; }

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