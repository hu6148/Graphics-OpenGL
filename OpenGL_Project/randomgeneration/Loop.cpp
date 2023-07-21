#include "Loop.h"

Loop::Loop() {
	loopPoints.clear();
	startLoopPointIdx = endLoopPointIdx = 0;

	sphereString.clear();
	maxNumOfSpheres = 5;
}

void Loop::addSphere() {
	/* Implement */
	// Add a  sphere
	// (1) when cntOfSpheres < maxNumOfSpheres
	// (2) when the last sphere is at start loop point

	if (sphereString.empty()) {
		Sphere sphere1(50.0f, 20, 20);
		sphere1.setCenter(Vector3f(loopPoints.front()[0], 0.0f, 0.0f));
		sphere1.setVelocity(Vector3f(1.0f, 0.0f, 0.0f));
		sphere1.setRandomProperties();
		sphereString.push_back(sphere1);
	}

	if (sphereString.size() < maxNumOfSpheres) {
		if (sphereString.back().getCenter()[0] >= loopPoints[startLoopPointIdx][0]) {

			Sphere sphere1(50.0f, 20, 20);
			sphere1.setCenter(Vector3f(loopPoints.front()[0], 0.0f, 0.0f));
			sphere1.setVelocity(Vector3f(1.0f, 0.0f, 0.0f));
			sphere1.setRandomProperties();
			sphereString.push_back(sphere1);
		}
	}
	if (sphereString.front().getCenter()[0] >= loopPoints.back()[0]) {
		sphereString.erase(sphereString.begin());
	}
}

void Loop::createLoop() {
	float radius = 50.0f;

	// create loop points
	// start loop
	for (int i = -boundaryX - radius; i < -boundaryX + radius; i++)
		loopPoints.push_back(Vector3f(i, 0.0f, 0.0f));
	// sphere loop
	startLoopPointIdx = loopPoints.size();
	for (int i = -boundaryX + radius; i <= boundaryX - radius; i++)
		loopPoints.push_back(Vector3f(i, 0.0f, 0.0f));
	endLoopPointIdx = loopPoints.size() - 1;
	// end loop
	for (int i = boundaryX - radius + 1; i <= boundaryX + radius; i++)
		loopPoints.push_back(Vector3f(i, 0.0f, 0.0f));

	// set sphere
	addSphere();
}

void Loop::moveSphere() {
	
	for (int i = 0; i < sphereString.size(); i++) {
		for (int i = 0; i < sphereString.size(); i++)
			sphereString[i].setCenter(Vector3f(sphereString[i].getCenter()[0] + sphereString[i].getVelocity()[0], 0.0f, 0.0f));
	}
}

void Loop::draw() {
	// draw spheres
	for (int i = 0; i < sphereString.size(); i++)
		sphereString[i].draw();

	// draw loop
	glDisable(GL_LIGHTING);
	glLineWidth(50.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.5f, 0.5f, 0.5f);
	for (int i = 0; i < loopPoints.size(); i++)
		glVertex3f(loopPoints[i][0], loopPoints[i][1], loopPoints[i][2]);
	glEnd();
}