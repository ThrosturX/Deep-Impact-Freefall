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

void SpaceScene::render(Ship ship)
{ // this will in the future, be PlayerShip
	static SDL_Point center = { 0, 0 };

	// calculate displacement
	// (translate ship's coordinates to 0, 0)
	displacement = ship.getCoordinates();

	displacement.x *= -1;
	displacement.y *= -1;

	// render the ship
	window->draw( ship.getImage(), center, NULL, ship.getAngle());
}

void SpaceScene::render(Celestial celestial)
{
	SDL_Point position;

	position = celestial.getCoordinates();

	position.x += displacement.x;
	position.y += displacement.y;

	window->draw( celestial.getImage(), position, NULL, celestial.getAngle() );
}