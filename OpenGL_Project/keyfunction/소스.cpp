#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;

enum SELECT_POINT { NONE = -1, PT1 = 0, PT2, PT3, PT4, POINT_SIZE };

SELECT_POINT selPt(NONE);
vector<vector<float>> points;
vector<vector<float>> colors;
vector<float> nonSelectedColor = { 1.0f, 1.0f, 1.0f };
vector<float> selectedColor = { 1.0f, 1.0f, 0.0f };
vector<float> selectingColor = { 1.0f, 0.0f, .0f };

void createPoints() {
	points.resize(POINT_SIZE);
	points[PT1].push_back(-0.5f);	points[PT1].push_back(0.5f);
	points[PT2].push_back(0.5f);	points[PT2].push_back(0.5f);
	points[PT3].push_back(-0.5f);	points[PT3].push_back(-0.5f);
	points[PT4].push_back(0.5f);	points[PT4].push_back(-0.5f);

	colors.resize(POINT_SIZE);
	for (int i = 0; i < colors.size(); i++)
		colors[i] = nonSelectedColor;
}

void drawPoints() {
	/* Implement: draw all points */
	glPointSize(20.0f);
	
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; i++) {
		glColor3f(colors[i][0], colors[i][1], colors[i][2]);
		glVertex2f(points[i][0], points[i][1]);
	}
		
	glEnd();
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawPoints();

	//glFlush();
	glFinish();
}

void keyboardDown(unsigned char key, int x, int y) {
	/* Implement */
	if(selPt != NONE) colors[selPt] = nonSelectedColor;
	switch (key) {
	case '1':
		selPt = PT1;
		colors[selPt] = selectingColor;
		break;
	case '2':
		selPt = PT2;
		colors[selPt] = selectingColor;
		break;
	case '3':
		selPt = PT3;
		colors[selPt] = selectingColor;
		break;
	case '4':
		selPt = PT4;
		colors[selPt] = selectingColor;
		break;
	default:
		colors[selPt] = selectedColor;
	}
	
	glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y) {
	/* Implement */
	colors[selPt] = selectedColor;
	glutPostRedisplay();
}


void specialKeyDown(int key, int x, int y) {
	/* Implement */
	if(selPt == NONE) {}
	else{
		switch (key) {
		case GLUT_KEY_UP:
			points[selPt][1] += 0.1f;
			break;
		case GLUT_KEY_DOWN:
			points[selPt][1] -= 0.1f;
			break;
		case GLUT_KEY_LEFT:
			points[selPt][0] -= 0.1f;
			break;
		case GLUT_KEY_RIGHT:
			points[selPt][0] += 0.1f;
			break;
		case GLUT_KEY_HOME:
			colors[selPt] = nonSelectedColor;
			selPt = NONE;
			break;
		}
	}
	
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Select and move points.");

	createPoints();

	// register callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(specialKeyDown);

	// enter GLUT event processing cycle
	glutMainLoop();
}
