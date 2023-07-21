#include <vector>
#include <algorithm>
#include <iostream>

#include "CollisionHandler.h"
#include "Light.h"
#include "SizeIs.h"

using namespace std;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 640		// window's width
#define WINDOW_HEIGHT 640		// window's height

#define boundaryX (WINDOW_WIDTH)/2
#define boundaryY (WINDOW_HEIGHT)/2

#define gap 10

Light light(boundaryX, boundaryY, boundaryX / 2, GL_LIGHT0);
vector<Sphere> spheres;
CollisionHandler colHandler;

void initialize() {
	// set light
	light.setAmbient(0.5, 0.5, 0.5, 1.0);
	light.setDiffuse(0.7, 0.7, 0.7, 1.0);
	light.setSpecular(1.0, 1.0, 1.0, 1.0);

	// create 100 spheres
	for (int i = 0; i < 100; i++) {
		float radius = rand() % (15 - 5 + 1) + 5;	// 5 ~ 15
		int x = -boundaryX + WINDOW_WIDTH / 10 * (i % 10) + gap * 2;
		static int y = -boundaryY + gap * 2;
		if (i > 0 && i % 10 == 0)
			y += WINDOW_HEIGHT / 10;

		float x_vel = (float)rand() / RAND_MAX * 2 - 1;
		float y_vel = (float)rand() / RAND_MAX * 2 - 1;
		spheres.push_back(Sphere(radius, 20, 20));
		spheres.back().setCenter(x, y, 0.0f);
		spheres.back().setVelocity(x_vel, y_vel, 0.0f);

		// set materials
		Material tmpMTL;
		tmpMTL.setAmbient((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 0.0f);
		spheres.back().setMTL(tmpMTL);
	}
}

void idle() {
	for (int i = 0; i < spheres.size(); i++)
		for (int j = i + 1; j < spheres.size(); j++)
			colHandler(spheres[i], spheres[j]);

	for (auto& sph : spheres) {
		if (sph.getCenter()[0] + sph.getRadius() >= boundaryX || sph.getCenter()[0] - sph.getRadius() <= -boundaryX)
			sph.setVelocity(-sph.getVelocity()[0], sph.getVelocity()[1], sph.getVelocity()[2]);
		if (sph.getCenter()[1] + sph.getRadius() >= boundaryY || sph.getCenter()[1] - sph.getRadius() <= -boundaryY)
			sph.setVelocity(sph.getVelocity()[0], -sph.getVelocity()[1], sph.getVelocity()[2]);
		sph.move();
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

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	light.draw();

	for (const auto& sph : spheres)
		sph.draw();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	SizeIs sizeIs;
	/* Implement: count and erase spheres */
	auto it = spheres.begin();
	if (key == 's') {
		sizeIs.setSize(SMALL);
		int cnt = count_if(spheres.begin(), spheres.end(), sizeIs);
		cout << "Number of small spheres : " << cnt << endl;
		erase_if(spheres, sizeIs);
	}
	else if (key == 'm') {
		sizeIs.setSize(MEDIUM);
		int cnt = count_if(spheres.begin(), spheres.end(), sizeIs);
		cout << "Number of medium spheres : " << cnt << endl;
		erase_if(spheres, sizeIs);
	}
	else if (key == 'l') {
		sizeIs.setSize(LARGE);
		int cnt = count_if(spheres.begin(), spheres.end(), sizeIs);
		cout << "Number of large spheres : " << cnt << endl;
		erase_if(spheres, sizeIs);
	}
}

int main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Display and erase the number of spheres of chosen size");
	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
