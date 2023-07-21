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
float Sphere::getCenterX() const { return center[0]; }
float Sphere::getCenterY() const { return center[1]; }
float Sphere::getCenterZ() const { return center[2]; }

void Sphere::setVelocity(float x, float y, float z) { 
	velocity[0] = x; velocity[1] = y; velocity[2] = z;
}

float Sphere::getVelocityX() const { return velocity[0]; }
float Sphere::getVelocityY() const { return velocity[1]; }
float Sphere::getVelocityZ() const { return velocity[2]; }


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
	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.getEmission());
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.getAmbient());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.getDiffuse());
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.getSpecular());
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.getShininess());
	
	glPushMatrix();
	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(radius, slice, stack);
	glPopMatrix();
}