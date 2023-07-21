#pragma once

#include "Sphere.h"

enum SIZE { SMALL, MEDIUM, LARGE};

class SizeIs {
public:
	SizeIs();
	void setSize(SIZE br);
	bool operator()(const Sphere& sph);
private:
	SIZE size;
};