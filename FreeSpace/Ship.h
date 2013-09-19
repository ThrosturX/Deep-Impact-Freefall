#pragma once
#include <cmath>
#include "entity.h"

#define PI 3.14159265

class Ship :
	public Entity
{
public:
	Ship(void);
	~Ship(void);

	void accelerate();
	void release();
	void update();

private:
	float getVelocity();

	bool accelerating;
	Vector2D ship_vector;
	float acceleration;
	float max_velocity;
	float turning_speed;
};

