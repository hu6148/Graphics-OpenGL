#include <iostream>
#include <string>

#include "Loop.h"
#include "Light.h"

Loop loop;
vector<Sphere> spheres;
Light light(boundaryX, boundaryY, boundaryX / 2, GL_LIGHT0);

clock_t start_t = clock();
clock_t end_t;

bool isCollisionDetected(const Sphere& sph1, const Sphere& sph2) {
	/* Implement */
	float dx = sph1.getCenter()[0] - sph2.getCenter()[0];
	float dy = sph1.getCenter()[1] - sph2.getCenter()[1];
	float dz = sph1.getCenter()[2] - sph2.getCenter()[2];
	float distance = sqrtf(dx * dx + dy * dy + dz * dz);

	return sph1.getRadius() + sph2.getRadius() > distance;
}

void handleCollision(Sphere& sph1, Sphere& sph2) {
	/* Implement */
	if (isCollisionDetected(sph1, sph2)) {
		float v1[3] = { sph1.getVelocity()[0], sph1.getVelocity()[1] ,sph1.getVelocity()[2] };
		float v2[3] = { sph2.getVelocity()[0], sph2.getVelocity()[1] ,sph2.getVelocity()[2] };
		float c1[3] = { sph1.getCenter()[0],sph1.getCenter()[1],sph1.getCenter()[2] };
		float c2[3] = { sph2.getCenter()[0],sph2.getCenter()[1],sph2.getCenter()[2] };
		float new_v1[3] = { v1[0] - (((v1[0] - v2[0]) * (c1[0] - c2[0]) + (v1[1] - v2[1]) * (c1[1] - c2[1])) / (pow(c1[0] - c2[0],2) + pow(c1[1] - c2[1],2))) * (c1[0] - c2[0]),
		v1[1] - (((v1[0] - v2[0]) * (c1[0] - c2[0]) + (v1[1] - v2[1]) * (c1[1] - c2[1])) / (pow(c1[0] - c2[0],2) + pow(c1[1] - c2[1],2))) * (c1[1] - c2[1]),
			0.0f
		};
		float new_v2[3] = { v2[0] - (((v2[0] - v1[0]) * (c2[0] - c1[0]) + (v2[1] - v1[1]) * (c2[1] - c1[1])) / (pow(c2[0] - c1[0],2) + pow(c2[1] - c1[1],2))) * (c2[0] - c1[0]),
		v2[1] - (((v2[0] - v1[0]) * (c2[0] - c1[0]) + (v2[1] - v1[1]) * (c2[1] - c1[1])) / (pow(c2[0] - c1[0],2) + pow(c2[1] - c1[1],2))) * (c2[1] - c1[1]),
			0.0f
		};
		sph1.setVelocity(new_v1[0], new_v1[1], new_v1[2]);
		sph2.setVelocity(new_v2[0], new_v2[1], new_v2[2]);
	}
}

void initialize() {
	light.setAmbient(0.5f, 0.5f, 0.5f, 1.0f);
	light.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	light.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);

	// set sphere
	Material mtl1;
	mtl1.setEmission(0.1f, 0.1f, 0.1f, 1.0f);
	mtl1.setAmbient(0.4f, 0.4f, 0.1f, 1.0f);
	mtl1.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	mtl1.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	mtl1.setShininess(10.0f);

	Material mtl2(mtl1), mtl3(mtl1);
	mtl2.setAmbient(0.1f, 0.4f, 0.4f, 1.0f);
	mtl3.setAmbient(0.4f, 0.1f, 0.4f, 1.0f);

	Sphere sphere1(50.0f, 20, 20);
	sphere1.setCenter(Vector3f(0.0f, -200.0f, 0.0f));
	sphere1.setVelocity(Vector3f(-1.0f, -1.8f, 0.0f));
	sphere1.setMTL(mtl1);
	spheres.push_back(sphere1);

	Sphere sphere2(sphere1);
	sphere2.setCenter(Vector3f(100.0f, 200.0f, 0.0f));
	sphere2.setVelocity(Vector3f(1.5f, 1.0f, 0.0f));
	sphere2.setMTL(mtl2);
	spheres.push_back(sphere2);

	Sphere sphere3(sphere1);
	sphere3.setCenter(Vector3f(-100.0f, 0.0f, 0.0f));
	sphere3.setVelocity(Vector3f(-3.0f, -3.0f, 0.0f));
	sphere3.setMTL(mtl3);
	spheres.push_back(sphere3);

	loop.createLoop();
}

void idle() {
	/* Implement */
	end_t = clock();

	if (end_t - start_t > 1000 / 60) {
		for (int i = 0; i < spheres.size(); i++) {
			for (int j = i + 1; j < spheres.size(); j++)
				handleCollision(spheres[i], spheres[j]);
		}

		for (int i = 0; i < spheres.size(); i++) spheres[i].move();

		loop.moveSphere();

		start_t = end_t;
	}
	glutPostRedisplay();

}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-boundaryX, boundaryX, -boundaryY, boundaryY, -100.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw 3D
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(light.getID());
	light.draw();

	for (int i = 0; i < (int)spheres.size(); i++)
		spheres[i].draw();

	loop.draw();

	glDisable(light.getID());
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("(1) Handle collisions among three spheres and (2) Move sphere along the loop");
	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
