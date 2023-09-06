#pragma once
#include "SDL.h"
#include "Cube.h"


void drawShape(SDL_Renderer* renderer, Cube shape);
void rotateShapeX(int theta, Cube &shape);
void rotateShapeY(int theta, Cube& shape);
void rotateShapeZ(int theta, Cube& shape);
void applyMatrix(double transMatrix[3][3], Cube& shape);
