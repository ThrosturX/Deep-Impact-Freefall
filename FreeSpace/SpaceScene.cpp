#include "SpaceScene.h"


SpaceScene::SpaceScene(Window *window, Player *player) : Scene(window)
{
	displacement.x =
	displacement.y = 0;
	celestials = new std::deque<Celestial>();
	starscape = new Starscape(window, &displacement);
	protagonist = player;
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

	position.x += displacement.x /* * 1.05 */;
	position.y += displacement.y /* * 1.05 */;

	window->draw( celestial.getImage(), position, NULL, celestial.getAngle() );
}
void SpaceScene::render_starscape()
{
	starscape->draw();
}

void SpaceScene::render()
{
	window->clear();

	// render the stars in the background
	render_starscape();

	// celestials
	for (std::deque<Celestial>::iterator it = begin(*celestials); it != end(*celestials); ++it) {
		render(*it);
	}

	// any asteroids

	// allies

	// projectiles

	// enemies

	// finally, render the player
	protagonist->ship.update();
	render(protagonist->ship);

	window->present();
}

SDL_Point SpaceScene::getDisplacement()
{
	return displacement;
}