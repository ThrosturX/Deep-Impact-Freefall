#include "Scene.h"


Scene::Scene(Window *_window)
{
	window = _window;
	cursor = new Image();
	cursor->open("res/ship.png", window->getRenderer());
}


Scene::~Scene(void)
{

}

void Scene::render(Entity item) {
	render(item, NULL);
}

void Scene::render(Entity item, SDL_Rect *clip) {
	window->draw( item.getImage(), item.getCoordinates(), clip, item.getAngle() );
}