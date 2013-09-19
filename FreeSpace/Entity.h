#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "Image.h"

struct Vector2D
{
	float x;
	float y;
};

class Entity
{
public:
	Entity(void);
	~Entity(void);

	float getAngle();
	SDL_Point getCoordinates();
	Image *getImage();
	std::string getName();

	void adjustAngle(float adjustment);
	void setAngle(float _angle);
	void setCoordinates(SDL_Point _coordinates);
	void setImage(Image *_image);
	void setName(std::string _name);

protected:
	float angle;
	SDL_Point coordinates;
	Image *image;
	std::string name;
};

