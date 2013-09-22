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

void SpaceScene::render_background()
{
	Celestial c;
	c.setImage(star);
	std::vector<SDL_Point> stars = starfield->getStarPoints(  );

	 /// broken!
	for (auto p = begin(stars); p < end(stars); ++p) {
		SDL_Point loc = { displacement.x - p->x , displacement.y - p->y };
		window->draw(star, loc, NULL, 0.0F );
	}

	SDL_Point loc;

	for (unsigned int i=0; i< stars.size(); ++i) {
		loc.x = (int) (displacement.x * 0.19 - stars.at(i).x );
		loc.y = (int) (displacement.y * 0.19 - stars.at(i).y );
	//	window->draw(star, loc, NULL, 70.0F);
	}
	
	stars = starfield->getParallax();
	for (unsigned int i=0; i< stars.size(); ++i) {
		loc.x = (int) (displacement.x * 0.165 - stars.at(i).x );
		loc.y = (int) (displacement.y * 0.165 - stars.at(i).y );
		window->draw(small_star, loc, NULL, 15.5F);
	}
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

	// enemies

	// finally, render the player
	protagonist->ship.update();
	render(protagonist->ship);

	window->present();
}