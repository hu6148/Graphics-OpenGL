#pragma once

#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <GL/glut.h>

using namespace std;

class Vertex {
public:
	Vertex();
	Vertex(float x, float y, float z);

	float pos[3];
};

class Face {
public:
	Face(const Vertex& v1, const Vertex& v2, const Vertex& v3);
	void draw() const;

	Vertex vrx[3];
};

class OBJ
{
public:
	OBJ();
	void draw() const;
	void ReadOBJFile(string filename);

	static float c;
	vector<Face> vFace;
};

