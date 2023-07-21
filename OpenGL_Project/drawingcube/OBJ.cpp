#include "OBJ.h"

float OBJ::c = 0;

Vertex::Vertex(){
	pos[0] = pos[1] = pos[2] = 0;
}
Vertex::Vertex(float x, float y, float z){
	pos[0] = x; pos[1] = y; pos[2] = z;
}

Face::Face(const Vertex& v1, const Vertex& v2, const Vertex& v3) {
	vrx[0] = v1; vrx[1] = v2; vrx[2] = v3;
}
void Face::draw() const {
	/* draw triangles */
	glColor3f(1.0f - OBJ::c, 1.0f - OBJ::c, 1.0f - OBJ::c);
	glBegin(GL_TRIANGLES);
	glVertex3f(vrx[0].pos[0], vrx[0].pos[1], vrx[0].pos[2]);
	glVertex3f(vrx[1].pos[0], vrx[1].pos[1], vrx[1].pos[2]);
	glVertex3f(vrx[2].pos[0], vrx[2].pos[1], vrx[2].pos[2]);
	glEnd();
	
}

OBJ::OBJ(){ }
void OBJ::draw() const {
	/* draw all faces */
	c = 0;
	for (int i = 0; i < 6; i++) {
		vFace[2 * i].draw();
		vFace[2 * i + 1].draw();
		c = c + 0.15;
	}
}
void OBJ::ReadOBJFile(string filename) {
	vector<Vertex> vertices;
	ifstream input(filename);
	char sub;
	while (input >> sub) {
		if (sub == 'v') {
			/* read vertex data */
			float x, y, z;
			input >> x; input >> y; input >> z;
			Vertex vertice(x, y, z);
			vertices.push_back(vertice);
		}
		else if (sub == 'f') {
			/* read face data */
			int a, b, c;
			input >> a; input >> b; input >> c;
			Face face(vertices[a - 1], vertices[b - 1], vertices[c - 1]);
			vFace.push_back(face);
		}
	}
}
