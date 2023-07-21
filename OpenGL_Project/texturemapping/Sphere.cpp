#include "Sphere.h"
#define WINDOW_WIDTH 640		
#define WINDOW_HEIGHT 640

Sphere::Sphere(float r, int sl, int st) :radius(r), slice(sl), stack(st) {}
void Sphere::setRadius(float r) { radius = r; }
float Sphere::getRadius() const { return radius; }
void Sphere::setSlice(int sl) { slice = sl; }
void Sphere::setStack(int st) { stack = st; }
void Sphere::setCenter(float x, float y, float z) { 
	center[0] = x; center[1] = y; center[2] = z; 
}
const float* Sphere::getCenter() const { return center; }
void Sphere::setVelocity(float x, float y, float z) { 
	velocity[0] = x; velocity[1] = y; velocity[2] = z;
}
const float* Sphere::getVelocity() const { return velocity; }
void Sphere::setMTL(const Material& m) { mtl = m; }
void Sphere::move(){
	if (center[0] + radius >= WINDOW_WIDTH / 2 || center[0] - radius <= -(WINDOW_WIDTH / 2))
		velocity[0] = -velocity[0];
	if (center[1] + radius >= WINDOW_HEIGHT / 2 || center[1] - radius <= -(WINDOW_HEIGHT / 2))
		velocity[1] = -velocity[1];
	center[0] += velocity[0];
	center[1] += velocity[1];
	center[2] += velocity[2];
}
void Sphere::draw() const{
	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.shininess);
	
	glPushMatrix();
	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(radius, slice, stack);
	glPopMatrix();
}