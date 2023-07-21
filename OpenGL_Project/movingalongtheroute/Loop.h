#pragma once

#include <vector>
using namespace std;

#include "Sphere.h"
#include "Constants.h"

class Loop
{
public:
	Loop();

	void createLoop();
	void moveSphere();

	void draw() const;

private:
	vector<Vector3f> loopPoints;

	Sphere sphereOnLoop;
};

