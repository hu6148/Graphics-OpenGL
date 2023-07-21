#pragma once

#include <math.h>
#include "Sphere.h"

class CollisionDetector
{
public:
	bool operator()(const Sphere& sph1, const Sphere& sph2);
};

