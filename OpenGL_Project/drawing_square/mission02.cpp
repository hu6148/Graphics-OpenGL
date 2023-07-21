#include <fstream>
#include <GL/glut.h>

using namespace std;

float x, y, len, r, g, b;

void readFile() {
	/* Implement: read square.txt */
	ifstream ifs("square.txt");
	ifs >> x >> y >> len >> r >> g >> b;
	ifs.close();
}

void drawSquare() {
	/* Implement: draw a square */
	glBegin(GL_QUADS);

	glColor3f(r, g, b);

	glVertex2f(x + len / 2, y + len / 2);
	glVertex2f(x - len / 2, y + len / 2);
	glVertex2f(x - len / 2, y - len / 2);
	glVertex2f(x + len / 2, y - len / 2);
	glEnd();
}

void renderScene() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	drawSquare();

	glFlush();
}

void main(int argc, char** argv) {
	readFile();

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Draw a square");

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
}
