#include "SpaceScene.h"


SpaceScene::SpaceScene(Window *window) : Scene(window)
{
	celestials = new std::deque<Celestial>();
}


SpaceScene::~SpaceScene(void)
{
}

void SpaceScene::initialize()
{
	// load stars as background
	star = new Image();
	star->open("star.png", window->getRenderer());
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

void SpaceScene::render_background()
{
	std::vector<SDL_Point> *stars = starfield.getStarPoints(  );
	/* /// broken!
	for (auto p = begin(*stars); p < end(*stars); ++p) {
		SDL_Point loc = { p->x - displacement.x, p->y - displacement.y };
		window->draw(star, loc, NULL, 0.0F );
	}*/
}