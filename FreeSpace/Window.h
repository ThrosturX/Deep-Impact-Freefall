#pragma once

#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "Image.h"
#include "Text.h"

class Window
{
public:
	Window(std::string title = "Window", int width = 800, int height = 600);
	~Window(void);

	SDL_Renderer *getRenderer();

	void draw(Image *image, SDL_Point location, SDL_Rect *clip = NULL, float angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Point *origin = nullptr);
	void draw_absolute(Image *image, SDL_Point location, SDL_Rect *clip = NULL, float angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw_scaled(Image *image, SDL_Point pivot, SDL_Rect location, SDL_Rect *clip = NULL, float angle = 0.0F, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clear();

	void present();

	SDL_Rect getBox();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Rect box;
};

