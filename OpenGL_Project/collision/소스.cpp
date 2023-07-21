#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "Sphere.h"
#include "Light.h"

using namespace std;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 640		// window's width
#define WINDOW_HEIGHT 640		// window's height

#define boundaryX (WINDOW_WIDTH)/2
#define boundaryY (WINDOW_HEIGHT)/2


clock_t start_t = clock();
clock_t end_t;

vector<Sphere> spheres;
Light light(boundaryX, boundaryY, boundaryX / 2, GL_LIGHT0);

void initialize() {
	light.setAmbient(0.5f, 0.5f, 0.5f, 1.0f);
	light.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	light.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);

	Material mtl1;
	mtl1.setEmission(0.1f, 0.1f, 0.1f, 1.0f);
	mtl1.setAmbient(0.4f, 0.4f, 0.1f, 1.0f);
	mtl1.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	mtl1.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	mtl1.setShininess(10.0f);

	Material mtl2(mtl1), mtl3(mtl1);
	mtl2.setAmbient(0.1f, 0.4f, 0.4f, 1.0f);
	mtl3.setAmbient(0.4f, 0.1f, 0.4f, 1.0f);

	Sphere sphere1(50, 20, 20);
	sphere1.setCenter(0.0f, -200.0f, 0.0f);
	sphere1.setVelocity(0.3f, 0.6f, 0.0f);
	sphere1.setMTL(mtl1);
	spheres.push_back(sphere1);

	Sphere sphere2(sphere1);
	sphere2.setCenter(100.0f, 200.0f, 0.0f);
	sphere2.setVelocity(-0.6f, -0.5f, 0.0f);
	sphere2.setMTL(mtl2);
	spheres.push_back(sphere2);

	Sphere sphere3(sphere1);
	sphere3.setCenter(-100.0f, 0.0f, 0.0f);
	sphere3.setVelocity(-2.0f, 2.0f, 0.0f);
	sphere3.setMTL(mtl3);
	spheres.push_back(sphere3);
}

bool isCollisionDetected(const Sphere& sph1, const Sphere& sph2) {
	/* Implement: collision detection */
	if (pow(sph1.getCenterX() - sph2.getCenterX(), 2) + pow(sph1.getCenterY() - sph2.getCenterY(), 2)
		<= pow(sph1.getRadius() + sph2.getRadius(), 2)) return true;
	else return false;
}

void handleCollision(Sphere& sph1, Sphere& sph2) {
	if (isCollisionDetected(sph1, sph2)) {
		/* Implement: collision handling */
		float v1[3] = { sph1.getVelocityX(), sph1.getVelocityY() ,sph1.getVelocityZ() };
		float v2[3] = { sph2.getVelocityX(), sph2.getVelocityY() ,sph2.getVelocityZ() };
		float c1[3] = { sph1.getCenterX(),sph1.getCenterY(),sph1.getCenterZ() };
		float c2[3] = { sph2.getCenterX(),sph2.getCenterY(),sph2.getCenterZ() };
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


void idle() {

	end_t = clock();

	if (end_t - start_t > 1000 / 60) {

		/* Handle collisions among spheres */
		for (int i = 0; i < spheres.size(); i++) {
			for (int j = i + 1; j < spheres.size(); j++)
				handleCollision(spheres[i], spheres[j]);
		}
		/* Implement: Handle boundary collision */
		spheres[0].move();
		spheres[1].move();
		spheres[2].move();
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

	/* Implement: Draw 2D (texture, ID and name)*/

	/* Implement: Draw 3D (light and spheres)*/
	glEnable(GL_LIGHTING);
	light.draw();

	spheres[0].draw(); spheres[1].draw(); spheres[2].draw();
	
	glDisable(GL_LIGHTING);

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Draw three spheres");
	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
