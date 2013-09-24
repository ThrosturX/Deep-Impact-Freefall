#include "SpaceScene.h"


SpaceScene::SpaceScene(Window *window, Player *player) : Scene(window)
{
	displacement.x =
	displacement.y = 0;
	celestials = new std::deque<Celestial>();
	starscape = new Starscape(window, &displacement);
	protagonist = player;
	cursor_frames = 0;
	cursor->open("res/cursor.png", window->getRenderer());
	SDL_ShowCursor(0);
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

void SpaceScene::activateCursor()
{
	SDL_SetTextureAlphaMod(cursor->getTexture(), static_cast<Uint8>(204));
	cursor_frames = 0;
}

void SpaceScene::render(Ship *ship)
{ // this will in the future, be PlayerShip
	static SDL_Point center = { 0, 0 };

	// calculate displacement
	// (translate ship's coordinates to 0, 0)
	displacement = ship->getCoordinates();

	displacement.x *= -1;
	displacement.y *= -1;

	// render the ship
	window->draw( ship->getImage(), center, NULL, ship->getAngle());
}

void SpaceScene::render(Celestial celestial)
{
	SDL_Point position;

	position = celestial.getCoordinates();

	position.x += displacement.x /* * 1.05 */;
	position.y += displacement.y /* * 1.05 */;

	window->draw( celestial.getImage(), position, NULL, celestial.getAngle() );
}

void SpaceScene::render_arrow(SDL_Point location)
{
#if _DEBUG
	std::cout << "Unimplemented: draw arrow towards center. Coordinates: " << location.x << ", " << location.y << std::endl;
#endif
}

void SpaceScene::render_cursor()
{
	SDL_Point loc;
	SDL_GetMouseState(&(loc.x), &(loc.y));

	window->draw_absolute(cursor, loc);
	if (cursor_frames > 90) {
		Uint8 alpha;
		SDL_GetTextureAlphaMod(cursor->getTexture(), &alpha);
		if (alpha > 0) {
			SDL_SetTextureAlphaMod(cursor->getTexture(), alpha-2);
		}
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

	// render directional arrow to center if far
	SDL_Point coordinates = protagonist->getShip()->getCoordinates();
	if (static_cast<int>(abs(coordinates.x)) > 2000  || static_cast<int>(abs(coordinates.y) > 2000))
		render_arrow(coordinates);

	// celestials
	for (std::deque<Celestial>::iterator it = begin(*celestials); it != end(*celestials); ++it) {
		render(*it);
	}

	// any asteroids

	// allies

	// projectiles

	// enemies

	// finally, render the player
	protagonist->getShip()->update();
	render(protagonist->getShip());

	// render the mouse, if it's on the screen
	if (++cursor_frames < 300) {
		render_cursor();
	}

	window->present();
}

SDL_Point SpaceScene::getDisplacement()
{
	return displacement;
}

Player *SpaceScene::getProtagonist()
{
	return protagonist;
}

Celestial *SpaceScene::getNearestCelestial()
{
	//TODO: find nearest celestial

	return &(celestials->at(0));
}