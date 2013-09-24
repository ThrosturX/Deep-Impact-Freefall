#pragma once

#include "Window.h"
#include "Entity.h"

class Scene
{
public:
	Scene(Window *_window);
	~Scene(void);
	
	void render(Entity item);
	void render(Entity item, SDL_Rect *clip);

protected:
	Window *window;
	Image *cursor;
};

