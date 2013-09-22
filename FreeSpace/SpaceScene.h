#pragma once

#include <deque>
#include "scene.h"
#include "celestial.h"
#include "Player.h"
#include "Starfield.h"
#include "Starscape.h"

class SpaceScene :
	public Scene
{
public:
	SpaceScene(Window *window, Player *player);
	~SpaceScene(void);

	std::deque<Celestial> *getCelestials();

	void addCelestial(Celestial celestial);

	void render(Ship ship);
	void render(Celestial celestial);
	void render_background();
	void render_starscape();
	void render();

private:
	std::deque<Celestial> *celestials;
	SDL_Point displacement;
	void initialize();
	Starfield *starfield;
	Starscape *starscape;
	Image *star;
	Image *small_star;
	Player *protagonist;
};

