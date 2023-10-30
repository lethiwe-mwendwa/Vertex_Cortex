#include "SDL.h"
#include <iostream>
#include "TriangularP.h"
#include "Vertex.h"
#include "Cube.h"
#include "Teapot.h"
#include "Entities.h"


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//Window and Renderer creation
	SDL_Window* window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	Cube* testTri = new Cube();
	//TriangularP* testTri = new TriangularP();

	renderEntities(renderer);
	//drawShape(renderer, *testCube);

	SDL_RenderPresent(renderer); // Update the screen


	//how to do the good ol thingy
	// rotate the cube relative to the shapes CENTERRR
	// instead of rotating it around the WORLD'S CENTERRRR
	// OH CRAP AND AND AND LITERALLY, SCALING A SHAPE IS
	// MOVING ITS POINTS AWAY/TU AND FROM RELATIVE TO ITSSSSS CENTERRR FUCK
	// IM GONNA CODE THIS RIGHTTT NOW
	


	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				SDL_Quit();
			}
			if (event.type == SDL_KEYDOWN) {
				std::cout << event.key.keysym.sym << std::endl;
				if (event.key.keysym.sym == 1073741906) {
					//rotate Entities
					for (int i = 0; i < Entities.size(); i++) {
						rotateShapeX(0.05,*Entities[i]);
					}
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 1073741905) {
					// Down arrow, rotate down
					//rotate Entities
					for (int i = 0; i < Entities.size(); i++){
						rotateShapeX(-0.05, *Entities[i]);
					}
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 1073741904) {
					// left arrow, rotate left
					for (int i = 0; i < Entities.size(); i++) {
						rotateShapeY(0.05, *Entities[i]);
					}
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 1073741903) {
					// left arrow, rotate left
					//rotateShapeY(-0.05, *testCube);
					rotateShapeY(-0.05, *testTri);
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 1073741913) {
					// left Z, rotate left
					//rotateShapeZ(-0.05, *testCube);
					rotateShapeZ(-0.05, *testTri);
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 1073741915) {
					// right Z, rotate right
					//rotateShapeZ(0.05, *testCube);
					rotateShapeZ(0.05, *testTri);
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 97) {
					// right Z, rotate right
					//moveShapeX(10, *testCube);
					moveShapeX(10, *testTri);
					renderEntities(renderer);
				} 
				if (event.key.keysym.sym == 119) {
					// right Z, rotate right
					//moveShapeY(-10, *testCube);
					moveShapeY(-10, *testTri);
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 115) {
					// right Z, rotate right
					//moveShapeY(10, *testCube);
					moveShapeY(10, *testTri);
					renderEntities(renderer);
				}
				if (event.key.keysym.sym == 100) {
					// right Z, rotate right
					//moveShapeX(-10, *testCube);
					moveShapeX(-10, *testTri);
					renderEntities(renderer);
				}
			}
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				drawShape(renderer, *testTri);
				SDL_RenderPresent(renderer);
			}
		}

	}
	SDL_Delay(500);
	SDL_Quit();
	return 0;
	
}