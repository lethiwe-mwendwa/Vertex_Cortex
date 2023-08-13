#pragma once
#include "SDL.h"
#include <vector>
#include <iostream>
using namespace std;

int SCREEN_WIDTH = 1020;
int SCREEN_HEIGHT = 720;
bool running = true;

struct Point3D {
	double x, y, z;
};

struct Vertex {
	int p1, p2;
};