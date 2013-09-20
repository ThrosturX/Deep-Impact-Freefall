#pragma once

#include <random>
#include "Entity.h"	// Vector2D

class Starfield
{
public:
	Starfield(int size = 1000);
	~Starfield(void);

	std::vector<SDL_Point> getStarPoints();
	std::vector<SDL_Point> getParallax();
	std::vector<SDL_Point> *getStarPoints(SDL_Point center);
	// privatize...
	std::vector<SDL_Point> *stars;
	std::vector<SDL_Point> *parallax; // TODO

private:
	void initialize(int size);
};

