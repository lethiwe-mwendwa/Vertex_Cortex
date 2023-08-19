#pragma once
#include "Constants.h"
#include <vector>
class Cube
{
public:
	Cube();

	std::vector<Point3D> points{ 
		Point3D{150,150,150},Point3D{150,150,-150},Point3D{-150,150,-150},Point3D{-150,150,150}, // A, B, C, D
		Point3D{150,-150,150}, Point3D{150,-150,-150}, Point3D{-150,-150,-150}, Point3D{-150,-150,150}  // E, F, G, H
	};

	std::vector<Vertex> vectices{
		Vertex{0,1},Vertex{1,2},Vertex{2,3},Vertex{3,0}, // top face
		Vertex{4,5},Vertex{5,6},Vertex{6,7},Vertex{7,4}, // bottom face
		Vertex{0,4},Vertex{1,5},Vertex{2,6},Vertex{3,7} // connecting parts
	};

};

