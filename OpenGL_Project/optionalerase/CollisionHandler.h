#pragma once

#include "CollisionDetector.h"

class CollisionHandler
{
public:
	void operator()(Sphere& sph1, Sphere& sph2);
};

