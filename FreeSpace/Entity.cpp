#include "Entity.h"


Entity::Entity(void)
{
	angle = 0.0F;
}


Entity::~Entity(void)
{
}

float Entity::getAngle() {
	return angle;
}

SDL_Point Entity::getCoordinates() {
	return coordinates;
}

Image *Entity::getImage() {
	return image;
}

void Entity::adjustAngle(float adjustment) {
	angle += adjustment;
}

void Entity::setAngle(float _angle) {
	angle = _angle;
}

void Entity::setCoordinates(SDL_Point _coordinates) {
	coordinates = _coordinates;
}

void Entity::setImage(Image *_image) {
	image = _image;
}

void Entity::setName(std::string _name) {
	name = _name;
}