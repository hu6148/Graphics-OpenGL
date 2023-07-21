#include "Shape3D.h"

Shape3D::Shape3D() {}
void Shape3D::setShape(SHAPE shp) {
	shape = shp;
}
void Shape3D::setPos(float x, float y, float z) {
	pos[0] = x; pos[1] = y; pos[2] = z;
}
void Shape3D::setAngleOfSpin(float ang) {
	angleOfSpin = ang;
}
void Shape3D::setAngleOfRevolution(float ang) {
	angleOfRevolution = ang;
}
void Shape3D::setSize(float s) {
	size = s;
}
void Shape3D::setMTL(const Material& m) {
	mtl = m;
}
void Shape3D::draw() const {
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.shininess);

	if (shape == TEAPOT) glutSolidTeapot(0.7 * size);
	if (shape == TORUS) glutSolidTorus(0.7*size, 1.4*size, 10, 10);
	if (shape == ICOSAHEDRON) glutSolidIcosahedron();
}