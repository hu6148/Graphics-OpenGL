#pragma once
class Vector3f
{
public:
	Vector3f();
	Vector3f(float x, float y, float z);
	void setPos(float x, float y, float z);
	float* getPos();
	float& operator[](const int i);
	float operator[](const int i) const;

private:
	float pos[3];
};

