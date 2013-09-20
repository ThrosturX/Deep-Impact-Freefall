#pragma once

#include <deque>
#include "scene.h"
#include "celestial.h"
#include "Ship.h"
#include "Starfield.h"

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
	void render_background();

private:
	std::deque<Celestial> *celestials;
	SDL_Point displacement;
	void initialize();
	Starfield starfield;
	Image *star;
};

