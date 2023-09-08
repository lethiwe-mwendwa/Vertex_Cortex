#pragma once
#include "SDL.h"
#include "Cube.h"


void drawShape(SDL_Renderer* renderer, Cube shape);
void rotateShapeX(double theta, Cube &shape);
void rotateShapeY(double theta, Cube& shape);
void rotateShapeZ(double theta, Cube& shape);
void applyMatrix(double transMatrix[3][3], Cube& shape);
