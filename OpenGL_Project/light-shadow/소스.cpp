#include <vector>

#include "Shape3D.h"
#include "Light.h"
#include <iostream>

using namespace std;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 640		// window's width
#define WINDOW_HEIGHT 640		// window's height

vector<Shape3D> shape3d;
vector<Light> lights;

float angle = 0.0f;

void initialize() {
	/* Implement: set lights and shape3d */
	Light light1;
	light1.setLightID(GL_LIGHT0);
	light1.setPosition(0.0f, 50.0f, 0.0f);
	light1.setAmbient(1.0f, 1.0f, 1.0f, 0.0f);
	light1.setDiffuse(1.0f, 1.0f, 1.0f, 0.0f);
	light1.setSpecular(1.0f, 1.0f, 1.0f, 0.0f);
	light1.enableLight(true);
	lights.push_back(light1);

	Light light2;
	light2.setLightID(GL_LIGHT1);
	light2.setPosition(50.0f, 0.0f, 0.0f);
	light2.setAmbient(0.5f, 0.5f, 0.5f, 0.0f);
	light2.setDiffuse(0.5f, 0.5f, 0.5f, 0.0f);
	light2.setSpecular(0.5f, 0.5f, 0.5f, 0.0f);
	light2.enableLight(true);
	lights.push_back(light2);

	Material material1;
	material1.setEmission(0.0f, 0.0f, 1.0f, 1.0f);
	material1.setAmbient(0.0215f, 0.1745f, 0.0215f, 0.55f);
	material1.setDiffuse(0.07568f, 0.61424f, 0.07568f, 0.55f);
	material1.setSpecular(0.633f, 0.727811f, 0.633f, 0.55f);
	material1.setShininess(76.8f);
	Shape3D shape3D1;
	shape3D1.setShape(Shape3D::TEAPOT);
	shape3D1.setPos(0.0f, 0.0f, 0.0f);
	shape3D1.setAngleOfSpin(angle);
	shape3D1.setAngleOfRevolution(angle);
	shape3D1.setSize(2.0f);
	shape3D1.setMTL(material1);
	shape3d.push_back(shape3D1);

	Material material2;
	material2.setEmission(0.0f, 1.0f, 0.0f, 1.0f);
	material2.setAmbient(0.19225f, 0.19225f, 0.19225f, 1.0f);
	material2.setDiffuse(0.50754f, 0.50754f, 0.50754f, 1.0f);
	material2.setSpecular(0.508273f, 0.508273f, 0.508273f, 1.0f);
	material2.setShininess(51.2f);
	Shape3D shape3D2;
	shape3D2.setShape(Shape3D::TORUS);
	shape3D2.setPos(0.0f, 0.0f, 0.0f);
	shape3D2.setAngleOfSpin(angle);
	shape3D2.setAngleOfRevolution(angle);
	shape3D2.setSize(0.5f);
	shape3D2.setMTL(material2);
	shape3d.push_back(shape3D2);

	Material material3;
	material3.setEmission(1.0f, 0.0f, 0.0f, 1.0f);
	material3.setAmbient(0.2125f, 0.1275f, 0.054f, 1.0f);
	material3.setDiffuse(0.714f, 0.4284f, 0.18144f, 1.0f);
	material3.setSpecular(0.393548f, 0.271906f, 0.166721f, 1.0f);
	material3.setShininess(25.6f);
	Shape3D shape3D3;
	shape3D3.setShape(Shape3D::ICOSAHEDRON);
	shape3D3.setPos(0.0f, 0.0f, 0.0f);
	shape3D3.setAngleOfSpin(angle);
	shape3D3.setAngleOfRevolution(angle);
	shape3D3.setSize(1.0f);
	shape3D3.setMTL(material3);
	shape3d.push_back(shape3D3);

}

void idle() {
	angle += 0.05f;

	glutPostRedisplay();
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	/* Implement: draw lights and shape3d */
	lights[0].draw(); lights[1].draw();

	shape3d[0].setAngleOfSpin(angle);
	
	glRotatef(shape3d[0].angleOfSpin, 0.0f, 1.0f, 0.0f);
	shape3d[0].draw();

	glPushMatrix();//
	shape3d[1].setPos(5.0f, 0.0f, 0.0f);
	shape3d[1].setAngleOfSpin(angle * 2);
	glTranslatef(shape3d[1].pos[0], shape3d[1].pos[1], shape3d[1].pos[2]);

	glPushMatrix();//
	glRotatef(shape3d[1].angleOfSpin, 0.0f, 1.0f, 0.0f);
	shape3d[1].draw();
	glPopMatrix();//
	glPopMatrix();//

	shape3d[2].setAngleOfRevolution(angle * 1.1);
	shape3d[2].setAngleOfSpin(angle * 1.5);
	shape3d[2].setPos(7.0f, 0.0f, 0.0f);
	
	glRotatef(shape3d[2].angleOfRevolution, 0.0f, 1.0f, 0.0f);
	glTranslatef(shape3d[2].pos[0], shape3d[2].pos[1], shape3d[2].pos[2]);
	glPushMatrix();
	glRotatef(shape3d[2].angleOfSpin, 0.0f, 1.0f, 0.0f);
	shape3d[2].draw();
	glPopMatrix();
	

	glDisable(lights[0].lightID); glDisable(lights[1].lightID);

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void keyboardDown(unsigned char key, int x, int y) {
	/* Implement: turn on/off lights */
	if(key == '1') {
		if (lights[0].isLightOn() == true) lights[0].enableLight(false);
		else lights[0].enableLight(true);
	}
	if(key == '2'){
		if (lights[1].isLightOn() == true) lights[1].enableLight(false);
		else lights[1].enableLight(true);
	}
}

int main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Draw three 3D-shapes with 2 lights");

	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardDown);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
