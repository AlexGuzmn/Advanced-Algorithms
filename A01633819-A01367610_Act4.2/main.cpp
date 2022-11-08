/*
 * Actividad 4.2 - Activity 4.2 Implementation of Convex Hulls applying Computational Geometry.
 * Andrés Alejandro Guzmán González - A01633819
 * José Pablo Naime García - A01367610
 *
 * Analysis and design of advanced algorithms
 * */




#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/Convex_hull_traits_adapter_2.h>
#include <CGAL/property_map.h>

#include <SDL2/SDL.h>

#include <vector>
#include <numeric>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SIMULATION_DELAY 1
#define SCALE 6

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Convex_hull_traits_adapter_2<K,
CGAL::Pointer_property_map<Point_2>::type> Convex_hull_traits_2;

using namespace std;

int main() {
  vector<Point_2> points = {};
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
	int x, y;
	cin >> x >> y;
	points.push_back(Point_2(x, y));
  }

  vector<size_t> indices(points.size()), out;
  vector < Point_2 * > resPointsRefs;
  iota(indices.begin(), indices.end(), 0);
  CGAL::convex_hull_2(indices.begin(), indices.end(), std::back_inserter(out),
					  Convex_hull_traits_2(CGAL::make_property_map(points)));
  for (size_t i : out) {
	std::cout << "points[" << i << "] = " << points[i] << std::endl;
	resPointsRefs.push_back(&points[i]);
  }

  // Graphics
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) == 0) {
	  SDL_bool done = SDL_FALSE;

	  while (!done) {
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_RenderSetScale(renderer, SCALE, SCALE);

		// SDL2 Anti-Aliasing
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


		// Lines
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		for (int i = 0; i < resPointsRefs.size(); i++) {
		  Point_2 *startPoint = resPointsRefs[i];
		  Point_2 *endPoint = resPointsRefs[(i + 1) % out.size()];

		  SDL_RenderDrawLine(renderer, startPoint->x(), startPoint->y(), endPoint->x(), endPoint->y());
		}
		// End Lines

		// Points
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		for (Point_2 point : points) {
		  SDL_RenderDrawPoint(renderer, point.x(), point.y());
		}
		// End Points



		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
		  if (event.type == SDL_QUIT) {
			done = SDL_TRUE;
		  }
		}
	  }
	}
  }

  return 0;
}