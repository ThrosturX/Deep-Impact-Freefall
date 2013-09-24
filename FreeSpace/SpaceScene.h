#pragma once

#include <deque>
#include "Scene.h"
#include "Celestial.h"
#include "Player.h"
#include "Starscape.h"

class SpaceScene :
	public Scene
{
public:
	SpaceScene(Window *window, Player *player);
	~SpaceScene(void);

	std::deque<Celestial> *getCelestials();

	void addCelestial(Celestial celestial);
	void activateCursor();

	void render(Ship *ship);
	void render(Celestial celestial);
	void render_arrow(SDL_Point location);
	void render_cursor();
	void render_starscape();
	void render();

	SDL_Point getDisplacement();

	Player *getProtagonist();

	Celestial *getNearestCelestial();

private:
	std::deque<Celestial> *celestials;
	SDL_Point displacement;
	void initialize();
	Starscape *starscape;
	Image *star;
	Image *small_star;
	Player *protagonist;
	int cursor_frames;
};

