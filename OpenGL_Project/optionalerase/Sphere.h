#pragma once

#include "Shape3D.h"

class Sphere : public Shape3D
{
public:
	Sphere(float r, int sl, int st);
	float getRadius() const;
	void draw() const;

private:
	float radius;
	int slice, stack;
};

