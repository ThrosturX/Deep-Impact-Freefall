#pragma once

#include "SDL2/SDL.h"
#include "SpaceScene.h"

class PlayerControls
{
public:
	PlayerControls(void(*end)(), SpaceScene *scene);
	~PlayerControls(void);

	void activate();

	// TODO: privatize
	SDL_Keycode DEF_UP;
	SDL_Keycode DEF_DOWN;
	SDL_Keycode DEF_LEFT;
	SDL_Keycode DEF_RIGHT;
	SDL_Keycode DEF_A; // accelerate
	SDL_Keycode DEF_B; // board ...
	SDL_Keycode DEF_F;
	SDL_Keycode DEF_J;
	SDL_Keycode DEF_L; // land
	SDL_Keycode DEF_P;
	SDL_Keycode DEF_R; // closest hostile
	SDL_Keycode DEF_S; // weapon safety
	SDL_Keycode DEF_W;
	SDL_Keycode DEF_ALT_L;
	SDL_Keycode DEF_CTRL_L;
	SDL_Keycode DEF_SHIFT_L;
	SDL_Keycode DEF_SPACE;
	SDL_Keycode DEF_ESCAPE;

private:
	void(*deactivate)();
	void assign();
	SpaceScene *scene;
};

