#include "SpaceScene.h"


SpaceScene::SpaceScene(Window *window, Player *player) : Scene(window)
{
	displacement.x =
	displacement.y = 0;
	system = new SolarSystem();
	starscape = new Starscape(window, &displacement);
	protagonist = player;
	cursor_frames = 0;
	cursor->open("res/cursor.png", window->getRenderer());
	SDL_ShowCursor(0);
	
	show_fps = false;
	fps_count = new Text(window->getRenderer());
	arrow = new Image();
	arrow->open("res/arrow.png", window->getRenderer());
}


SpaceScene::~SpaceScene(void)
{
}

std::deque<Celestial> *SpaceScene::getCelestials()
{
	return system->getCelestials();
}

void SpaceScene::addCelestial(Celestial celestial)
{
	system->addCelestial(celestial);
}

void SpaceScene::activateCursor()
{
	SDL_SetTextureAlphaMod(cursor->getTexture(), static_cast<Uint8>(204));
	cursor_frames = 0;
}

void SpaceScene::toggleFps()
{
	show_fps = !show_fps;
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
	static int rendered_times = 0;

	if (rendered_times < 100) {
		double angle = 270 + atan2(location.y, location.x) * 180 / PI;
		SDL_Point center = {0, 0};
		SDL_Rect rect = window->getBox();
		SDL_Point pivot = { rect.w / 2, rect.h / 2};

 		window->draw_scaled(arrow, pivot, rect, NULL, static_cast<float>(angle));
	} else if (rendered_times > 200) {
		rendered_times = 0;
	}

	++rendered_times;
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

void SpaceScene::render_fps()
{
	static SDL_Point location = { 30, 20 };
	static time_t last = 0;
	static int fps = -1;
	static int frames = 1;

	time_t now = SDL_GetTicks();
	time_t dt = now - last;
	if ( dt > 250) {
		last = now;

		if (dt) { // avoid division by zero
			fps = util::round(frames * 1000 / static_cast<double>(dt));
		}

		std::string output = "fps: " + std::to_string(fps);

		fps_count->setText(output);
		frames = 1;
	} else {
		++frames;
	}

	window->draw_absolute(fps_count, location);
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
	for (std::deque<Celestial>::iterator it = begin(*(system->getCelestials())); it != end(*(system->getCelestials())); ++it) {
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

	if (show_fps) {
		render_fps();
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

	return &(system->getCelestials()->at(0));
}