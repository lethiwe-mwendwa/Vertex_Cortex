#include "SDL.h"
#include "Cube.h"
#include "Vertex.h"
#include "Constants.h"
#include <iostream>
int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//Window and Renderer creation
	SDL_Window* window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	Cube* testCube = new Cube();

	drawShape(renderer,*testCube);
	SDL_RenderPresent(renderer); // Update the screen

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				SDL_Quit();
			}
			if (event.type == SDL_KEYDOWN) {
				std::cout << event.key.keysym.sym << std::endl;
				if (event.key.keysym.sym == 1073741906) {
					// Up arrow, rotate up
					rotateShapeX(0.05,*testCube);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					drawShape(renderer, *testCube);
					SDL_RenderPresent(renderer);
				}
				if (event.key.keysym.sym == 1073741905) {
					// Down arrow, rotate down
					rotateShapeX(-0.05, *testCube);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					drawShape(renderer, *testCube);
					SDL_RenderPresent(renderer);
				}
				if (event.key.keysym.sym == 1073741904) {
					// left arrow, rotate left
					rotateShapeY(0.05, *testCube);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					drawShape(renderer, *testCube);
					SDL_RenderPresent(renderer);
				}
				if (event.key.keysym.sym == 1073741903) {
					// left arrow, rotate left
					rotateShapeY(-0.05, *testCube);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					drawShape(renderer, *testCube);
					SDL_RenderPresent(renderer);
				}
				if (event.key.keysym.sym == 1073741913) {
					// left Z, rotate left
					rotateShapeZ(-0.05, *testCube);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					drawShape(renderer, *testCube);
					SDL_RenderPresent(renderer);
				}
				if (event.key.keysym.sym == 1073741915) {
					// right Z, rotate right
					rotateShapeZ(0.05, *testCube);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					drawShape(renderer, *testCube);
					SDL_RenderPresent(renderer);
				}
			}
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				drawShape(renderer, *testCube);
				SDL_RenderPresent(renderer);
			}
		}

	}
	SDL_Delay(500);
	SDL_Quit();
	return 0;
	
}