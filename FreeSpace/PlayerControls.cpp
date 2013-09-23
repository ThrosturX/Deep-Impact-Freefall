#include "PlayerControls.h"


PlayerControls::PlayerControls(void(*end)())
{
	deactivate = end;
	assign();
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
				SDL_Keysym action = e.key.keysym.sym;
			}
		}
	}
}

void PlayerControls::assign()
{

}