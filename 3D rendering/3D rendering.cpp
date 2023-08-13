#include "Constants.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//Window and Renderer creation
	SDL_Window* window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;
	//SDL_Surface* icon = SDL_LoadBMP("assets/gameIcon.BMP");
	//SDL_SetWindowIcon(window, icon);
	//SDL_FreeSurface(icon);

	int cubeIndices[] = {
		0, 1, 1, 2, 2, 3, 3, 0,   // Front face
		4, 5, 5, 6, 6, 7, 7, 4,   // Back face
		0, 4, 1, 5, 2, 6, 3, 7    // Connecting edges
	};



	SDL_SetRenderDrawColor(renderer, 100, 34, 2, 100);

	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);


	SDL_RenderPresent(renderer); // Update the screen



	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_RETURN) {

				}
			}
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			}
		}


	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set drawing color to white
	SDL_RenderClear(renderer); // Clear the renderer

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set drawing color to black


	//SDL_RenderDrawLine(renderer, x1, x2, y1, y2)

	return 0;
}