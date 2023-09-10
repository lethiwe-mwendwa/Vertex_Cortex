#include "Vertex.h"
#include "Entities.h"
#include <iostream>

std::vector<Shape*> Entities;

void renderEntities(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	std::cout << "this is the size:" << Entities.size();
	for (int i = 0; i < Entities.size(); i++){
		drawShape(renderer, *Entities[i]);
		std::cout << "shape has been drawn?";
	}
	SDL_RenderPresent(renderer);
}