#include "SDL2/SDL.h"
using namespace std;

struct Line{
    int x1, y1, x2, y2;
};

int main(int argc, char* argv[]){

  // Read input



  // Initialize SDL for graphics
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
	  SDL_bool done = SDL_FALSE;

	  while (!done) {
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
		SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
		SDL_RenderDrawLine(renderer, 340, 240, 320, 200);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 0, 0, 320, 200);


		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
		  if (event.type == SDL_QUIT) {
			done = SDL_TRUE;
		  }
		}
	  }
	}

	if (renderer) {
	  SDL_DestroyRenderer(renderer);
	}
	if (window) {
	  SDL_DestroyWindow(window);
	}
  }

  SDL_Quit();
  return 0;
}