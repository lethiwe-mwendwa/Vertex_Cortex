#pragma once
#include "SDL.h"
#include "Cube.h"


void drawShape(SDL_Renderer* renderer, Cube shape);
void rotateShape(int theta, Cube &shape);
