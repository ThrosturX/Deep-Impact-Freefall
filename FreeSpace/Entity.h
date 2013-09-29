#pragma once


#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include "Image.h"

enum DIR_ANGLE { LEFT = -1, STOP = 0, RIGHT = 1, REVERSE };

class Entity
{
public:
	Entity(void);
	~Entity(void);

	float getAngle();
	SDL_Point getCoordinates();
	Image *getImage();
	std::string getName();

	void adjustAngle(double adjustment);
	void setAngle(double _angle);
	void setCoordinates(Vector2D _coordinates);
	void setImage(Image *_image);
	void setName(std::string _name);

protected:
	double angle;
	Vector2D coordinates;
	Image *image;
	std::string name;
};

