#pragma once

#include <deque>
#include "Celestial.h"

class SolarSystem
{
public:
	SolarSystem(void);
	~SolarSystem(void);

	std::deque<Celestial> *getCelestials();
	void addCelestial(Celestial celestial);

private:
	std::deque<Celestial> *celestials;
};

