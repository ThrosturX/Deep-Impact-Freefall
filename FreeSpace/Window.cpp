#include "Window.h"


Window::Window(std::string title, int width, int height)
{
	// Set window size
	box.x = box.y = 0;
	box.w = width;
	box.h = height;

	// Create window
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, box.w, box.h, SDL_WINDOW_SHOWN);

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}


Window::~Window(void)
{
}

SDL_Renderer *Window::getRenderer() {
	return renderer;
}

void Window::draw(Image *image, SDL_Point center, SDL_Rect *clip, float angle, SDL_RendererFlip flip) {

	SDL_Rect screen = getBox();

	SDL_Rect rect;
	rect.x = ((screen.w - image->getWidth()) / 2) + center.x;
	rect.y = ((screen.h - image->getHeight()) / 2) + center.y;
	rect.h = image->getHeight();
	rect.w = image->getWidth();

	SDL_Point pivot = { (rect.h / 2), (rect.w / 2) };

	SDL_RenderCopyEx(renderer, image->getTexture(), clip, &rect, angle, &pivot, flip); 
}

void Window::clear() {
	SDL_RenderClear(renderer);
}

void Window::present() {
	SDL_RenderPresent(renderer);
}

SDL_Rect Window::getBox() {
	SDL_GetWindowSize(window, &box.w, &box.h);
	return box;
}