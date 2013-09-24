#include "PlayerControls.h"


PlayerControls::PlayerControls(void(*end)(), SpaceScene *_scene)
{
	deactivate = end;
	assign();
	scene = _scene;
}


PlayerControls::~PlayerControls(void)
{
}

void PlayerControls::activate()
{
	SDL_Event e;
	bool inactive = false;
	while (!inactive) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				deactivate();
			}
			if (e.type == SDL_KEYDOWN) {
				SDL_Keycode action = e.key.keysym.sym;
				Ship *ship = (scene->getProtagonist())->getShip();

				if (action == DEF_A) {
					ship->turn(ship->getSelectedItem());
				} else if (action == DEF_UP) {
					ship->accelerate();
				} else if (action == DEF_LEFT) {
					ship->turn(LEFT);
				} else if (action == DEF_RIGHT) {
					ship->turn(RIGHT);
				} else if (action == DEF_DOWN) {
					ship->turn(REVERSE);
				} else if (action == DEF_L) {
					// try to land

					// if didn't land, set selected item to nearest celestial
					ship->setSelectedItem(scene->getNearestCelestial());
				}
				// TODO: Replace this with something mucho better
				else if (action == DEF_ESCAPE) {
					deactivate();
				}

				if (action == DEF_SPACE) {
					std::cout << "(" << ship->getCoordinates().x << ", " << ship->getCoordinates().y << ")" << std::endl;
				}
			}
			else if (e.type == SDL_KEYUP) {
				SDL_Keycode action = e.key.keysym.sym;
				Ship *ship = (scene->getProtagonist())->getShip();

				if (action == DEF_UP) {
					ship->release();
				} else if (action == DEF_A) {
					ship->disableAP();
				} else if (action == DEF_LEFT || action == DEF_RIGHT || action == DEF_DOWN) {
					ship->turn(STOP);
				}
			}
		}
		scene->render();
	}
}

void PlayerControls::assign()
{
	// arrow keys
	DEF_UP    = SDLK_UP;
	DEF_DOWN  = SDLK_DOWN;
	DEF_LEFT  = SDLK_LEFT;
	DEF_RIGHT = SDLK_RIGHT;

	// letters
	DEF_A = SDLK_a;
	DEF_B = SDLK_b;
	DEF_J = SDLK_j;
	DEF_L = SDLK_l;
	DEF_P = SDLK_p;
	DEF_R = SDLK_r;
	DEF_S = SDLK_s;
	DEF_W = SDLK_w;

	// numbers

	// other
	DEF_ALT_L   = SDLK_LALT;
	DEF_CTRL_L  = SDLK_LCTRL;
	DEF_SHIFT_L = SDLK_LSHIFT;
	DEF_SPACE   = SDLK_SPACE;
	DEF_ESCAPE  = SDLK_ESCAPE;
}