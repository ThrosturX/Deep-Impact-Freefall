#include <iostream>
#include <string>
#include "SDL2/sdl.h"
#include "SDL2/SDL_image.h"
#include "SpaceScene.h"
#include "Window.h"
#include "Celestial.h"
#include "Ship.h"

int main(int argc, char** argv){

	// Initialize EVERYTHING
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Quit();
		return -1;
	}

	Window *window = new Window("FreeSpace");

	SDL_Point center = {0, 0};

	Image *png_ship = new Image();
	png_ship->open("res/rom.png", window->getRenderer());
	
	Player *player = new Player(png_ship);

	Ship ship;

	ship.setName("Player");
	ship.setCoordinates( center );
	ship.setImage(png_ship);
	ship.setAngle(0.0);

	Image *png_planet = new Image();
	png_planet->open("res/planet.png", window->getRenderer());
	Celestial planet;
	planet.setName("Earth");
	planet.setCoordinates( center );
	planet.setImage(png_planet);
	planet.setAngle(26.5);


	/**/
	SpaceScene scene(window, player);
	scene.addCelestial(planet);

	/// TODO: Move into a controls handler

	std::cout << "Loading... complete?" << std::endl;
	
	SDL_Event e;
	bool quit = false;
	while(!quit) {
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym) {
					//For quitting, escape key
					case SDLK_ESCAPE:
						quit = true;
						break;
					case SDLK_UP:
						player->ship.accelerate();
						break;
					case SDLK_LEFT:
						player->ship.turn(LEFT);
						break;
					case SDLK_RIGHT:
						player->ship.turn(RIGHT);
						break;
					case SDLK_DOWN:
						player->ship.turn(REVERSE);
				}
			}
			else if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
					case SDLK_UP:
						player->ship.release();
						break;
					case SDLK_LEFT:
					case SDLK_RIGHT:
					case SDLK_DOWN:
						player->ship.turn(STOP);
						break;
				}
			}
		}

		scene.render();
	}
	
	SDL_Quit();

	return 0;
}