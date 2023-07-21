#include "CollisionDetector.h"

/* Implement */
bool CollisionDetector::operator()(const Sphere& sph1, const Sphere& sph2){
	return (pow(sph1.getCenter()[0] - sph2.getCenter()[0], 2)
		+ pow(sph1.getCenter()[1] - sph2.getCenter()[1], 2)
		<= pow(sph1.getRadius() + sph2.getRadius(), 2));
}