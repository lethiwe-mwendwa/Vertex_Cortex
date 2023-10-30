#pragma once
#include "Shape.h"
#include "Entities.h"

class Teapot : public Shape
{
public:
    Teapot() : Shape()
    {
        pointNum = 8;
        vecticesNum = 12;
        points = {
            Point3D{30.0, 0.0, 0.0},      // A
            Point3D{15.0, 0.0, 25.98},    // B
            Point3D{-15.0, 0.0, 25.98},   // C
            Point3D{-30.0, 0.0, 0.0},     // D
            Point3D{0.0, 25.98, 0.0},    // E
            Point3D{15.0, 25.98, -25.98}, // F
            Point3D{-15.0, 25.98, -25.98},// G
            Point3D{0.0, 51.96, 0.0}     // H
        };

        vectices = {
            Vertex{0, 1}, Vertex{1, 2}, Vertex{2, 3}, Vertex{3, 0}, // Top face
            Vertex{4, 5}, Vertex{5, 6}, Vertex{6, 7}, Vertex{7, 4}, // Bottom face
            Vertex{0, 4}, Vertex{1, 5}, Vertex{2, 6}, Vertex{3, 7}  // Connecting edges
        };
    }
};



