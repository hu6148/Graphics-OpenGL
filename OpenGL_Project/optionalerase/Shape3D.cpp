#include "Shape3D.h"

Shape3D::Shape3D() {
	VectorN<float, 3> tmp;
	center = velocity = tmp;
}

void Shape3D::setCenter(float x, float y, float z) {
	center[0] = x;
	center[1] = y;
	center[2] = z;
}

void Shape3D::setCenter(const VectorN<float, 3>& c) {
	center = c;
}

VectorN<float, 3> Shape3D::getCenter() const {
	return center;
}

void Shape3D::setVelocity(float x, float y, float z) {
	velocity[0] = x;
	velocity[1] = y;
	velocity[2] = z;
}

void Shape3D::setVelocity(const VectorN<float, 3>& v) {
	velocity = v;
}

VectorN<float, 3> Shape3D::getVelocity() const {
	return velocity;
}

void Shape3D::move() {
	center = center + velocity;
}

void Shape3D::setMTL(const Material& m) {
	mtl.setEmission(m.getEmission()[0], m.getEmission()[1], m.getEmission()[2], m.getEmission()[3]);
	mtl.setAmbient(m.getAmbient()[0], m.getAmbient()[1], m.getAmbient()[2], m.getAmbient()[3]);
	mtl.setDiffuse(m.getDiffuse()[0], m.getDiffuse()[1], m.getDiffuse()[2], m.getDiffuse()[3]);
	mtl.setSpecular(m.getSpecular()[0], m.getSpecular()[1], m.getSpecular()[2], m.getSpecular()[3]);
	mtl.setShininess(m.getShininess()[0]);
}

const Material& Shape3D::getMTL() const {
	return mtl;
}