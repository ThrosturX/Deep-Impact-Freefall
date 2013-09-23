#pragma once

#include <SDL2/SDL.h>

class PlayerControls
{
public:
	PlayerControls(void(*end)());
	~PlayerControls(void);

	void activate();

	// TODO: privatize
	int accelerate;

private:
	void(*deactivate)();
	void assign();
};

