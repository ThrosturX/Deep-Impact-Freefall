#include "Entity.h"

Vector2D::Vector2D()
{
	// intentionally empty
}

Vector2D::Vector2D(SDL_Point p)
{
	x = p.x;
	y = p.y;
}

Entity::Entity(void)
{
	angle = 0.0F;
}


Entity::~Entity(void)
{
}

float Entity::getAngle() {
	return static_cast<float>(angle);
}

SDL_Point Entity::getCoordinates() {
	SDL_Point p;
	p.x = (int) coordinates.x;
	p.y = (int) coordinates.y;
	return p;
}

Image *Entity::getImage() {
	return image;
}

std::string Entity::getName()
{
	return name;
}

void Entity::adjustAngle(double adjustment) {
	angle += adjustment;
}

void Entity::setAngle(double _angle) {
	angle = _angle;
}

void Entity::setCoordinates(Vector2D _coordinates) {
	coordinates = _coordinates;
}

void Entity::setImage(Image *_image) {
	image = _image;
}

void Entity::setName(std::string _name) {
	name = _name;
}