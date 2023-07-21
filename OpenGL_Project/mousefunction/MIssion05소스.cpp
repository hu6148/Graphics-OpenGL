#include <iostream>
#include <GL/glut.h>
#include "Point.h"

using namespace std;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

Point pt1;	// falling point 1
Point pt2;	// falling point 2
float mPos[2];	// mouse point
bool bLMBDown;	// state of whether LBM is down

void initialize() {
	/* Implement */
	pt1.color[0] = 1.0f; pt1.color[1] = 0.0f; pt1.color[2] = 1.0f;
	pt2.color[0] = 1.0f; pt2.color[1] = 1.0f; pt2.color[2] = 0.0f;
	pt1.speed = -0.005f; pt2.speed = -0.01f;
	pt1.center[0] = -0.5f; pt1.center[1] = 0.0f;
	pt2.center[0] = 0.5f; pt2.center[1] = 0.0f;
	pt1.pointSize = 10.0f; pt2.pointSize = 20.0f;
}

void idle() {
	/* Implement */
	if (bLMBDown == false) {
		if (pt1.center[1] < -1.0f)
			pt1.center[1] = 1.0f;
		if (pt2.center[1] < -1.0f)
			pt2.center[1] = 1.0f;

		pt1.center[1] += pt1.speed;
		pt2.center[1] += pt2.speed;

		glutPostRedisplay();
	}
	
}

void drawPoints() {
	/* Implement */
		glPointSize(pt1.pointSize);
		glColor3f(pt1.color[0], pt1.color[1], pt1.color[2]);
		glBegin(GL_POINTS);
		glVertex2f(pt1.center[0], pt1.center[1]);
		glEnd();

		glPointSize(pt2.pointSize);
		glColor3f(pt2.color[0], pt2.color[1], pt2.color[2]);
		glBegin(GL_POINTS);
		glVertex2f(pt2.center[0], pt2.center[1]);
		glEnd();
	glutPostRedisplay();
}

void drawStippleLine() {
	/* Implement */
	if (bLMBDown == true) {
		glLineWidth(5.0f);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(1, 0x00FF);
		glBegin(GL_LINES);
		glColor3f(pt1.color[0], pt1.color[1], pt1.color[2]);
		glVertex2f(pt1.center[0], pt1.center[1]);
		glColor3f(pt2.color[0], pt2.color[1], pt2.color[2]);
		glVertex2f(pt2.center[0], pt2.center[1]);
		glEnd();
	}
	if (bLMBDown == false) {
		glLineWidth(5.0f);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(3, 0xAAAA);
		glBegin(GL_LINE_LOOP);

		glColor3f(pt1.color[0], pt1.color[1], pt1.color[2]);
		glVertex2f(pt1.center[0], pt1.center[1]);
		glColor3f(pt2.color[0], pt2.color[1], pt2.color[2]);
		glVertex2f(pt2.center[0], pt2.center[1]);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(mPos[0], mPos[1]);
		glEnd();
	}
	glutPostRedisplay();
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawPoints();
	drawStippleLine();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	/* Implement */
	printf("(%d, %d, %d, %d)\n", button, state, x, y);

	if (state == GLUT_UP) bLMBDown = false;
	if (state == GLUT_DOWN) {
		bLMBDown = true;
		pt1.center[0] = (float)x/(WINDOW_WIDTH/2) - 1;
		pt1.center[1] = -((float)y/(WINDOW_HEIGHT/2) -1);
		pt2.center[0] = (float)x / (WINDOW_WIDTH / 2) - 1;
		pt2.center[1] = -((float)y / (WINDOW_HEIGHT / 2) - 1);
	}
}

void mouseMove(int x, int y) {
	/* Implement */
	printf("Moved (%d, %d)\n", x, y);

	pt2.center[0] = (float)x / (WINDOW_WIDTH / 2) - 1;
	pt2.center[1] = -((float)y / (WINDOW_HEIGHT / 2) - 1);
}

void mousePassiveMove(int x, int y) {
	/* Implement */
	printf("Passively-moved (%d, %d)\n", x, y);

	mPos[0] = (float)x / (WINDOW_WIDTH / 2) - 1;
	mPos[1] = -((float)y / (WINDOW_HEIGHT / 2) - 1);
}

void main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Draw two falling points with distance lines");

	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);
	glutPassiveMotionFunc(mousePassiveMove);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}