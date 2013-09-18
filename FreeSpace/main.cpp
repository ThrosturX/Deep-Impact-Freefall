#include <iostream>
#include <string>
#include "SDL2/sdl.h"
#include "SDL2/SDL_image.h"
#include "Scene.h"
#include "Window.h"

int main(int argc, char** argv){

	// Initialize EVERYTHING
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Quit();
		return -1;
	}

	Window window("FreeSpace");

	// TODO: Entity.h and so on -- and maybe a background!

	SDL_Point center = {0, 0};
	Image *image = new Image();

	image->open("res/triangle.bmp", window.getRenderer());

	SDL_Event e;
	bool quit = false;
	float angle = 0.0;
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
					case SDLK_LEFT:
						angle -= 4;
						break;
					case SDLK_RIGHT:
						angle += 4;
						break;
				}
			}
		}

		window.clear();
		window.draw(image, center, NULL, angle);
		window.present();
	}

	SDL_Quit();

	return 0;

	///////// END /////////
	///////// END /////////

	/*
    //Start our window
	Window window;
    try {
        window.Init("FreeSpace");
    }
    catch (const std::runtime_error &e){
        std::cout << e.what() << std::endl;
        window.Quit();
        return -1;
    }

	Scene scene(&window);

	scene.render();


	// STOP
	std::cin.ignore();

    //Load up an image and some text
    SDL_Texture *img, *msg;
    try {
        //Load the image
        std::string imgFile = "res/pizza-sprite.png";
        img = window.LoadImage(imgFile);
        //Load the font and message
        std::string fontFile = "res/SourceSansPro-Regular.ttf";
        std::string text = "TTF Fonts too!";
        SDL_Color color = { 255, 255, 255 };
        msg = window.RenderText(text, fontFile, color, 25);
    }
    catch (const std::runtime_error &e){
        //Catch error and crash
        std::cout << e.what() << std::endl;
        window.Quit();
        return -1;
    }
    //Set a position to draw it with
    SDL_Rect pos = { window.Box().w / 2 - 150 / 2,
        window.Box().h / 2 - 150 / 2, 150, 150 };
    //The angle to draw at, so we can play with it
    int angle = 0;

    //Our event structure
	SDL_Event e;
	//For tracking if we want to quit
	bool quit = false;
	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			//If user closes he window
			if (e.type == SDL_QUIT)
				quit = true;
			//If user presses any key
			if (e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym){
                    //For rotating image
                    case SDLK_d:
                        angle += 2;
                        break;
                    case SDLK_a:
                        angle -= 2;
                        break;
					//For quitting, escape key
					case SDLK_ESCAPE:
						quit = true;
						break;
					default:
						break;
				}
			}
		}
        //RENDERING
        window.Clear();

        window.Draw(img, pos, NULL, angle);
        window.Draw(msg, pos, NULL, angle, 0, 0, SDL_FLIP_VERTICAL);

        window.Present();
	}
    SDL_DestroyTexture(img);
    SDL_DestroyTexture(msg);
	window.Quit();

	return 0;
	*/
}