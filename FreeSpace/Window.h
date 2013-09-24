#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Image.h"

class Window
{
public:
	Window(std::string title = "Window", int width = 800, int height = 600);
	~Window(void);

	SDL_Renderer *getRenderer();

	void draw(Image *image, SDL_Point location, SDL_Rect *clip = NULL, float angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw_absolute(Image *image, SDL_Point location, SDL_Rect *clip = NULL, float angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clear();

	void present();

	SDL_Rect getBox();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Rect box;
};

