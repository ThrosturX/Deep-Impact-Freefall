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
	

	Image *image = new Image();
	image->open("res/triangle.bmp", window->getRenderer());
	Image *png_ship = new Image();
	png_ship->open("res/ship.png", window->getRenderer());
	
	Ship ship;

	ship.setName("Player");
	ship.setCoordinates( center );
	ship.setImage(png_ship);
	ship.setAngle(0.0F);

	Image *png_planet = new Image();
	png_planet->open("res/planet.png", window->getRenderer());
	Celestial planet;
	planet.setName("Earth");
	planet.setCoordinates( center );
	planet.setImage(png_planet);
	planet.setAngle(20.0);


	/**/
	SpaceScene scene(window);
	scene.addCelestial(planet);

	// TODO: check the physics behavior
	
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
						ship.accelerate();
						break;
					case SDLK_LEFT:
						ship.turn(LEFT);
						break;
					case SDLK_RIGHT:
						ship.turn(RIGHT);
						break;
				}
			}
			else if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
					case SDLK_UP:
						ship.release();
						break;
					case SDLK_LEFT:
					case SDLK_RIGHT:
						ship.turn(STOP);
						break;
				}
			}
		}

		window->clear();
		scene.render_background();
		scene.render(planet);	// for now; this will change and be handled by SpaceScene
		ship.update();
		scene.render(ship);
		//window->draw(image, center, NULL, 0.0F);
		window->present();
	}
	
	SDL_Quit();

	return 0;
}