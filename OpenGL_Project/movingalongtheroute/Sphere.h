#pragma once
#include "Material.h"
#include "Vector3f.h"
#include <GL/glut.h>

class Sphere
{
public:
	Sphere();
	Sphere(float r, int sl, int st);
	void setRadius(float r);
	float getRadius() const;
	void setSlice(int sl);
	void setStack(int st);
	void setCenter(float x, float y, float z);
	void setCenter(const Vector3f& cen);
	Vector3f getCenter() const;
	void setVelocity(float x, float y, float z);
	void setVelocity(const Vector3f& vel);
	Vector3f getVelocity() const;
	void setLoopPointIdx(int idx);
	int getLoopPointIdx() const;
	void move();
	void setMTL(const Material& m);
	void draw() const;

private:
	float radius;
	int slice;
	int stack;
	Vector3f center;
	Vector3f velocity;
	Material mtl;
	int loopPointIdx;
};

