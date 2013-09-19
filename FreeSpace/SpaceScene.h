#pragma once
#include <deque>
#include "scene.h"
#include "celestial.h"
#include "Ship.h"

class SpaceScene :
	public Scene
{
public:
	SpaceScene(Window *window);
	~SpaceScene(void);

	std::deque<Celestial> *getCelestials();

	void addCelestial(Celestial celestial);

	void render(Ship ship);
	void render(Celestial celestial);

private:
	std::deque<Celestial> *celestials;
	SDL_Point displacement;
};

