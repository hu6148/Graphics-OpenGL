#include <iostream>
#include <GL/glut.h>

using namespace std;

enum MENU { QUIT = -1, CLEAR = 0, POINT, LINES, LINE_STRIP, LINE_LOOP } menu;

const int pointSize = 6;
const int pDim = 2;
const int cDim = 3;
float pts[pointSize][pDim];
float color[pointSize][cDim];

void createPoints() {
	pts[0][0] = -0.8f;	pts[0][1] = -0.8f;
	pts[1][0] = -0.2f;	pts[1][1] = -0.8f;
	pts[2][0] = -0.5f;	pts[2][1] = 0.8f;
	pts[3][0] = 0.2f;	pts[3][1] = 0.8f;
	pts[4][0] = 0.5f;	pts[4][1] = -0.8f;
	pts[5][0] = 0.8f;	pts[5][1] = 0.8f;

	color[0][0] = 1.0f;	color[0][1] = 0.0f;	color[0][2] = 0.0f;
	color[1][0] = 0.0f;	color[1][1] = 1.0f;	color[1][2] = 0.0f;
	color[2][0] = 0.0f;	color[2][1] = 0.0f;	color[2][2] = 1.0f;
	color[3][0] = 1.0f;	color[3][1] = 1.0f;	color[3][2] = 0.0f;
	color[4][0] = 0.0f;	color[4][1] = 1.0f;	color[4][2] = 1.0f;
	color[5][0] = 1.0f;	color[5][1] = 0.0f;	color[5][2] = 1.0f;
}

void sub_menu(int option) {
	cout << "Sub menu: " << option << endl;

	menu = (MENU)option;

	glutPostRedisplay();
}

void main_menu(int option) {
	cout << "Main menu: " << option << endl;
	if (option == QUIT)
		exit(0);

	menu = (MENU)option;

	glutPostRedisplay();
}

void createPopupMenu() {
	/* Implement: create popup menu */
	int mainmenu, draw, line;

	line = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Lines", 2);
	glutAddMenuEntry("Line Strip", 3);
	glutAddMenuEntry("Line Loop", 4);

	draw = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Point", 1);
	glutAddSubMenu("Line", line);

	mainmenu = glutCreateMenu(main_menu);
	glutAddMenuEntry("Quit", -1);
	glutAddMenuEntry("Clear", 0);
	glutAddSubMenu("Draw", draw);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void drawPrimitives() {
	/* Implement: draw primitives */
	//Clear
	if (menu == 0) {
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex2f(1.0, 1.0);
			glVertex2f(-1.0, 1.0);
			glVertex2f(-1.0, -1.0);
			glVertex2f(1.0, -1.0);
		glEnd();
	}

	//Point
	if (menu == 1) {
		glPointSize(10.0f);
		glBegin(GL_POINTS);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();
	}
		

	//Lines
	if (menu == 2) {
		glLineWidth(5.0f);
		glBegin(GL_LINES);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();

	}
		

	//Line Strip
	if (menu == 3) {
		glLineWidth(5.0f);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();
	}
		

	//Line Loop
	if (menu == 4) {
		glLineWidth(5.0f);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();
	}
}

void renderScene() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	drawPrimitives();

	glFlush();
	// glFinish();
}

void main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Draw primitives using popup menu");

	createPopupMenu();
	createPoints();

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
}
