#include "Vector3f.h"

Vector3f::Vector3f(){}
Vector3f::Vector3f(float x, float y, float z) :pos{x,y,z} {}
void Vector3f::setPos(float x, float y, float z) { pos[0] = x; pos[1] = y; pos[2] = z; }
float* Vector3f::getPos() { return pos; }
float& Vector3f::operator[](const int i) { return pos[i]; }
float Vector3f::operator[](const int i) const { return pos[i]; }
