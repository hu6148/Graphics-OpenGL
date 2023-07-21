#include "Loop.h"

Loop::Loop() {
	loopPoints.clear();
}

void Loop::createLoop() {
	float radius = 50.0f;
	
	// create loop points
	for (int i = -boundaryX - radius; i <= boundaryX + radius; i++)
		loopPoints.push_back(Vector3f(i, 0.0f, 0.0f));

	// set sphere
	Material mtl;
	mtl.setEmission(0.1f, 0.1f, 0.1f, 1.0f);
	mtl.setAmbient(0.3f, 0.1f, 0.1f, 1.0f);
	mtl.setDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
	mtl.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	mtl.setShininess(50.0f);

	sphereOnLoop.setRadius(radius);
	sphereOnLoop.setSlice(30);
	sphereOnLoop.setStack(30);
	sphereOnLoop.setMTL(mtl);
	sphereOnLoop.setLoopPointIdx(0);
	sphereOnLoop.setCenter(loopPoints[0]);
}

void Loop::moveSphere() {
	int currLoopPtIdx = sphereOnLoop.getLoopPointIdx();
	int newLoopPtIdx = currLoopPtIdx == loopPoints.size() - 1 ? 0 : currLoopPtIdx + 1;
	sphereOnLoop.setLoopPointIdx(newLoopPtIdx);
	sphereOnLoop.setCenter(loopPoints[newLoopPtIdx]);
}

void Loop::draw() const {
	// draw sphere
	sphereOnLoop.draw();

	// draw loop
	glDisable(GL_LIGHTING);
	glLineWidth(sphereOnLoop.getRadius());
	glBegin(GL_LINE_STRIP);
	glColor3f(0.5f, 0.5f, 0.5f);
	for (int i = 0; i < loopPoints.size(); i++)
		glVertex3f(loopPoints[i][0], loopPoints[i][1], loopPoints[i][2]);
	glEnd();
}