#pragma once
#include "SDL.h"
#include "Shape.h"

void moveShapeX(double x, Shape& shape);
void moveShapeY(double x, Shape& shape);
void moveShapeY(double x, Shape& shape);

void drawShape(SDL_Renderer* renderer, Shape shape);

void rotateShapeX(double theta, Shape&shape);
void rotateShapeY(double theta, Shape& shape);
void rotateShapeZ(double theta, Shape& shape);
void applyMatrix(double transMatrix[3][3], Shape& shape);
