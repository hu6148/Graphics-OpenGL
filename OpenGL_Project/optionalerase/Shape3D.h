#pragma once

#include "Material.h"
#include <GL/glut.h>

class Shape3D
{
public:
	Shape3D();

	void setCenter(float x, float y, float z);
	void setCenter(const VectorN<float, 3>& c);
	VectorN<float, 3> getCenter() const;
	void setVelocity(float x, float y, float z);
	void setVelocity(const VectorN<float, 3>& v);
	VectorN<float, 3> getVelocity() const;
	void move();
	void setMTL(const Material& m);

	const Material& getMTL() const;

	virtual void draw() const = 0;

protected:
	VectorN<float, 3> center;
	VectorN<float, 3> velocity;
	Material mtl;
};

