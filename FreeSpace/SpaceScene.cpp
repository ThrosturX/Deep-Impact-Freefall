#include "SpaceScene.h"


SpaceScene::SpaceScene(Window *window) : Scene(window)
{
	celestials = new std::deque<Celestial>();
}


SpaceScene::~SpaceScene(void)
{
}

std::deque<Celestial> *SpaceScene::getCelestials()
{
	return celestials;
}

void SpaceScene::addCelestial(Celestial celestial)
{
	celestials->push_back(celestial);
}
