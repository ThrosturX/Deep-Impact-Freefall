#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

// Simple wrapper class for using images
class Image
{
public:

	Image()
	{
	}

	~Image(void)
	{
		SDL_DestroyTexture(tex);
	}

	void open(const std::string &file, SDL_Renderer *renderer) {
		tex = IMG_LoadTexture(renderer, file.c_str());
		SDL_QueryTexture(tex, NULL, NULL, &width, &height);
	}

	SDL_Texture* getTexture() { return tex; }

	void setSize(int w, int h) {
		width = w;
		height = h;
	}

	int getWidth()  { return width;  }
	int getHeight() { return height; }

private:
	SDL_Texture *tex;
	int width;
	int height;
};

