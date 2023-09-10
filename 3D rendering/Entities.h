#pragma once
#include "SDL.h"
#include "Shape.h"

extern std::vector<Shape*> Entities;

void renderEntities(SDL_Renderer* renderer);