#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "Image.h"

class Entity
{
public:
	Entity(void);
	~Entity(void);

private:
	float angle;
	SDL_Point coordinates;
	Image image;
	std::string name;
};

