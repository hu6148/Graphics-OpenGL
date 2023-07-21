#include "Shape3D.h"

Shape3D::Shape3D(){}
void Shape3D::setCenter(const Vector3f& c) {
	center.setPos(c[0], c[1], c[2]);
}
Vector3f Shape3D::getCenter() const { return center; }
void Shape3D::setVelocity(const Vector3f& v) {
	velocity.setPos(v[0], v[1], v[2]);
}
Vector3f Shape3D::getVelocity() const { return velocity; }
void Shape3D::move() {
	center[0] += velocity[0];
	center[1] += velocity[1];
	center[2] += velocity[2];
}
void Shape3D::setMTL(const Material& m) {
	mtl = m;
}

