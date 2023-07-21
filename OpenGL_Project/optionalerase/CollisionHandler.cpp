#include "CollisionHandler.h"

/* Implement */
CollisionDetector collisionDetector;
void CollisionHandler:: operator()(Sphere& sph1, Sphere& sph2) {
	
		if (collisionDetector(sph1, sph2)) {
			float dVx = sph1.getVelocity()[0] - sph2.getVelocity()[0];
			float dVy = sph1.getVelocity()[1] - sph2.getVelocity()[1];
			float dVz = sph1.getVelocity()[2] - sph2.getVelocity()[2];

			float dx = sph1.getCenter()[0] - sph2.getCenter()[0];
			float dy = sph1.getCenter()[1] - sph2.getCenter()[1];
			float dz = sph1.getCenter()[2] - sph2.getCenter()[2];

			float dVel[3] = { dVx, dVy, dVz };
			float dCen[3] = { dx, dy, dz };

			float numerator = dVx * dx + dVy * dy + dVz * dz;
			float denominator = dx * dx + dy * dy + dz * dz;

			float delta_vel[3];
			delta_vel[0] = (numerator / denominator) * dCen[0];
			delta_vel[1] = (numerator / denominator) * dCen[1];
			delta_vel[2] = (numerator / denominator) * dCen[2];

			sph1.setVelocity(sph1.getVelocity()[0] - delta_vel[0], sph1.getVelocity()[1] - delta_vel[1], sph1.getVelocity()[2] - delta_vel[2]);
			sph2.setVelocity(sph2.getVelocity()[0] + delta_vel[0], sph2.getVelocity()[1] + delta_vel[1], sph2.getVelocity()[2] + delta_vel[2]);
		}
}