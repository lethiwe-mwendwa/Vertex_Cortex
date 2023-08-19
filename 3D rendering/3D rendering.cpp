#include "SDL.h"
#include "Cube.h"
#include "Vertex.h"
#include "Constants.h"
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
				if (event.key.keysym.sym == SDLK_RETURN) {

				}
			}
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			}
		}

	}

	SDL_Quit();
	return 0;
	
}