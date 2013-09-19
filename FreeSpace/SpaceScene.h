#pragma once
#include <deque>
#include "scene.h"
#include "celestial.h"

class SpaceScene :
	public Scene
{
public:
	SpaceScene(Window *window);
	~SpaceScene(void);

	std::deque<Celestial> *getCelestials();

	void addCelestial(Celestial celestial);


private:
	std::deque<Celestial> *celestials;
};

