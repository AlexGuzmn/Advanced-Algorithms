#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SIMULATION_DELAY 1
#define COLLISION_DETECTION_OFFSET 1

using namespace std;

struct Line {
  int id;
  int x1, y1, x2, y2;
  int A, B, C;
  double slope;
  bool shouldBeCompared;
  bool isIntersecting;

  Line(int x1, int y1, int x2, int y2, int id) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;

	this->A = y2 - y1;
	this->B = x1 - x2;
	this->C = x2 * y1 - x1 * y2;

	this->id = id;

	this->isIntersecting = false;
  }

  bool isInsideScreen() {
	return (x1 >= 0 && x1 <= SCREEN_WIDTH && y1 >= 0 && y1 <= SCREEN_HEIGHT) ||
		(x2 >= 0 && x2 <= SCREEN_WIDTH && y2 >= 0 && y2 <= SCREEN_HEIGHT);
  }

  int getXPosition(double y) {
	return (double)(-C - B * y) / (1.0 * A);
  }

  void isBetweenHorizontalLine(double y) {
	shouldBeCompared = (y1 <= y && y2 >= y) || (y1 >= y && y2 <= y);
  }

  void print() {
	cout << "\nLine-" << id << " : (" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ")" << endl;
	cout << "A: " << A << " B: " << B << " C: " << C << " Slope: " << slope << endl;
  }
};

int main(int argc, char *argv[]) {
  vector < Line * > lines;
  vector < Line * > linesToCompare;

  // Simulation Variables
  bool paused = false;

  // Read input
  int n = 0;
  cin >> n;

  // Create Lines
  for (int i = 0; i < n; i++) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	Line *line = new Line(x1, y1, x2, y2, i);

	line->print();

	// Check if line is inside the screen
	if (line->isInsideScreen()) {
	  lines.push_back(line);
	} else {
	  cout << "^ Is outside the screen\n" << endl;
	}
  }

  double currH = 0;

  // Draw lines
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) == 0) {
	  SDL_bool done = SDL_FALSE;

	  while (!done) {
		SDL_Event event;

		linesToCompare.clear();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		// Normal Lines
		for (Line *line : lines) {
		  // Check if line should be considered to be compared
		  line->isBetweenHorizontalLine(currH);

		  // Render Line
		  if (line->isIntersecting) {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		  } else if (line->shouldBeCompared) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
		  } else {
			// Default color
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		  }

		  SDL_RenderDrawLine(renderer, line->x1, line->y1, line->x2, line->y2);

		  if (line->shouldBeCompared) {
			linesToCompare.push_back(line);
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawPoint(renderer, line->getXPosition(currH), currH);
		  }
		}

		if (!paused) {
		  if (currH < SCREEN_HEIGHT) {
			if (linesToCompare.size() > 1) {
			  // Sort lines by x position
			  sort(linesToCompare.begin(), linesToCompare.end(), [currH](Line *a, Line *b) {
				return a->getXPosition(currH) < b->getXPosition(currH);
			  });

			  cout << "\n\nCOMPARING---------------- in: " << currH << endl;
			  // print lines
			  for (Line *line : linesToCompare) {
				line->print();
				cout << "XPos: " << line->getXPosition(currH) << endl;
			  }

			  // Check if lines are intersecting
			  for (int i = 0; i < linesToCompare.size() - 1; i++) {
				Line *line1 = linesToCompare[i];
				Line *line2 = linesToCompare[i + 1];

				// Check if line1 is intersecting with line2
				if (line2->getXPosition(currH) - line1->getXPosition(currH) < COLLISION_DETECTION_OFFSET ) {
				  line1->isIntersecting = true;
				  line2->isIntersecting = true;
				}
			  }
			}

			currH+= 0.5;
			SDL_SetRenderDrawColor(renderer, 255, 145, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(renderer, 0, currH, SCREEN_WIDTH, currH);
		  }
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(SIMULATION_DELAY);

		while (SDL_PollEvent(&event)) {
		  if (event.type == SDL_QUIT) {
			done = SDL_TRUE;
		  }

		  if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_SPACE) {
			  currH = 0;
			} else if (event.key.keysym.sym == SDLK_DOWN) {
			  paused = !paused;
			}
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