#include "SolarSystem.h"


SolarSystem::SolarSystem(void)
{
	celestials = new std::deque<Celestial>();
}


SolarSystem::~SolarSystem(void)
{
}

std::deque<Celestial> *SolarSystem::getCelestials()
{
	return celestials;
}

void SolarSystem::addCelestial(Celestial celestial)
{
	celestials->push_back(celestial);
}