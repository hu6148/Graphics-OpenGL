#pragma once
#include "Material.h"
#include <GL/glut.h>

class Sphere
{
public:
	Sphere(float r, int sl, int st);
	void setRadius(float r);
	float getRadius() const;
	void setSlice(int sl);
	void setStack(int st);

	void setCenter(float x, float y, float z);
	float getCenterX() const;
	float getCenterY() const;
	float getCenterZ() const;

	void setVelocity(float x, float y, float z);
	float getVelocityX() const;
	float getVelocityY() const;
	float getVelocityZ() const;
	
	void move();
	void setMTL(const Material& m);
	void draw() const;

private:
	float radius;
	int slice;
	int stack;
	float center[3];
	float velocity[3];
	Material mtl;

};

