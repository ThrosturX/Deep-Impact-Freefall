#pragma once

#include <random>
#include "Entity.h"	// Vector2D

class Starfield
{
public:
	Starfield(void);
	Starfield(int size);
	~Starfield(void);

	std::vector<SDL_Point> *getStarPoints();
	std::vector<SDL_Point> *getStarPoints(SDL_Point center);

	std::vector<SDL_Point> *stars;
};

