#pragma once

#include <deque>
#include <algorithm>
#include <random>
#include "Window.h"

struct Star {
	Image file;
	SDL_Point pos;
	double layer;
};

class Starscape
{
public:
	Starscape(Window* win, SDL_Point *displacement);
	~Starscape(void);

	void draw();

private:
	bool is_visible(Star s);

	Window *window;
	SDL_Rect area;
	SDL_Point *direction;
	Image *images;
	int num_images;
	std::deque<Star> stars;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> *horizontal;
	std::uniform_int_distribution<int> *vertical;
	std::uniform_real_distribution<double> *layering;
};

