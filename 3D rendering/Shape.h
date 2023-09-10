#pragma once
#include <vector>
#include "Constants.h"

class Shape
{
public:
	Shape();
	int pointNum = 0;
	int vecticesNum = 0;
	std::vector<Point3D> points{};

	std::vector<Vertex> vectices{};
};


