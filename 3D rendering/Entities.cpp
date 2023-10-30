#include "Vertex.h"
#include "Entities.h"
#include <iostream>

std::vector<Shape*> Entities;

void renderEntities(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	for (int i = 0; i < Entities.size(); i++){
		drawShape(renderer, *Entities[i]);
	}
	SDL_RenderPresent(renderer);
}

void transformEntities(SDL_Renderer* renderer, char axis, int value)
{
	switch (axis) {
	case('X'):
		for (int i = 0; i < Entities.size(); i++) {
			rotateShapeX(value, *Entities[i]);
		}
		break;
	case('Y'):
		for (int i = 0; i < Entities.size(); i++) {
			rotateShapeY(value, *Entities[i]);
		}
	case('Z'):
		for (int i = 0; i < Entities.size(); i++) {
			rotateShapeY(value, *Entities[i]);
		}
	}
	
	renderEntities(renderer);

}
