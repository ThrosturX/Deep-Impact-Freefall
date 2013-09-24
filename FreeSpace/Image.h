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
		// TODO: check if this image already has a texture and destroy it if necessary.
		tex = IMG_LoadTexture(renderer, file.c_str());
		SDL_QueryTexture(tex, NULL, NULL, &width, &height);

		if (tex == NULL)
			std::cerr << "Error loading image " << file.c_str() << ": " << SDL_GetError() << std::endl;
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

