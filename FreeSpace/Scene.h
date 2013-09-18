#pragma once

#include "Window.h"

class Scene
{
public:
	Scene(Window *_window);
	~Scene(void);
	
	void render();

private:
	Window *window;
};

