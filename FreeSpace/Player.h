#pragma once

#include "Ship.h"

class Player
{
public:

	Player(Image *img)
	{
		SDL_Point c = {0, 0};
		ship.setName("Player"); // TODO: replace literals
		ship.setCoordinates(c);
		ship.setImage(img);
		ship.setAngle(0.0);
	}

	~Player(void) { }

	Ship *getShip() { return &ship; }

	Ship ship;
};

