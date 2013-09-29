#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SpaceScene.h"
#include "Window.h"
#include "Celestial.h"
#include "Ship.h"
#include "PlayerControls.h"

void engine_exit();

int main(int argc, char** argv){

	// Initialize EVERYTHING
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Quit();
		return -1;
	}
	if (TTF_Init() == -1){
	 std::cout << TTF_GetError() << std::endl;
		SDL_Quit();
		return 2;
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

	center.x = 150;
	center.y = -100;
	png_planet = new Image();
	png_planet->open("res/moon.png", window->getRenderer());
	png_planet->setSize(100, 100);
	Celestial moon;
	moon.setName("Luna");
	moon.setCoordinates(center);
	moon.setImage(png_planet);
	moon.setAngle(-15.0);

	SpaceScene scene(window, player);
	scene.addCelestial(planet);
	scene.addCelestial(moon);
	/// TODO: Move into a controls handler

	void (*end)();
	end = &engine_exit;

	PlayerControls flight(end, &scene);
	flight.activate();

	/*
	SDL_Event e;
	bool quit = false;
	while (!quit) {
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
					case SDLK_a:
						player->ship.turn(player->ship.getSelectedItem());
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
						break;
					case SDLK_l:
						player->ship.setSelectedItem(&( scene.getCelestials()->at(0)));
						//std::cout << "l ";
						//std::cout << player->ship.getSelectedItem()->getName() << std::endl;
						break;
				}
			}
			else if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
					case SDLK_UP:
						player->ship.release();
						break;
					case SDLK_a:
						player->ship.disableAP();
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
	*/
	SDL_Quit();

	return 0;
}

void engine_exit()
{
	SDL_Quit();
	exit(0);
}
