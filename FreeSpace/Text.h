#pragma once
#include <string>
#include "SDL2/SDL_ttf.h"
#include "image.h"

class Text :
	public Image
{
public:
	Text(SDL_Renderer *_renderer)
	{
		renderer = _renderer;
		font = nullptr;
		color.r = 255;
		color.g = 255;
		color.b = 255;
		modify("res/SourceSansPro-Regular.ttf", 12);
		setText("Deep Impact");
	}

	~Text()
	{
		if (font)
			TTF_CloseFont(font);
	}

	void modify(std::string font_file, int fontsize)
	{
		TTF_Font *f;

		f = TTF_OpenFont(font_file.c_str(), fontsize);

		if (f == nullptr) { // probably TODO on error handling
			std::cerr << "Failed to load font: " + font_file + TTF_GetError() << std::endl;
			return;
		}

		font = f;
	}

	void setText(std::string message)
	{
		SDL_Surface *surf = TTF_RenderText_Solid(font, message.c_str(), color);
		tex = SDL_CreateTextureFromSurface(renderer, surf);
		SDL_QueryTexture(tex, NULL, NULL, &width, &height);

		SDL_FreeSurface(surf);
	}

private:
	SDL_Renderer *renderer;
	TTF_Font *font;
	SDL_Color color;
};

