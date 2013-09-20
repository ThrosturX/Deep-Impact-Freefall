#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include "Image.h"

enum DIR_ANGLE { LEFT = -1, STOP = 0, RIGHT = 1 };

class Vector2D
{
public:
	Vector2D();
	Vector2D(SDL_Point p);

	double x;
	double y;

	friend bool operator<(const Vector2D &lhs, const Vector2D &rhs)
	{
		return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
	}
	friend bool operator>(const Vector2D &lhs, const Vector2D &rhs)
	{
		return std::tie(lhs.x, lhs.y) > std::tie(rhs.x, rhs.y);
	}
	/*
	static std::vector<Vector2D>::iterator start (std::vector<Vector2D> v, SDL_Point tl, SDL_Point br)
	{
		Vector2D v_tl(tl); 
		Vector2D v_br(br);

		std::vector<Vector2D>::iterator partition_end = std::stable_partition(begin(v), end(v), [tl, br](const Vector2D &p) { return p > tl && p < br; });

		return partition_end;
	}*/
};

class Entity
{
public:
	Entity(void);
	~Entity(void);

	float getAngle();
	SDL_Point getCoordinates();
	Image *getImage();
	std::string getName();

	void adjustAngle(float adjustment);
	void setAngle(float _angle);
	void setCoordinates(Vector2D _coordinates);
	void setImage(Image *_image);
	void setName(std::string _name);

protected:
	float angle;
	Vector2D coordinates;
	Image *image;
	std::string name;
};

