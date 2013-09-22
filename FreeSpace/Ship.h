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
	void turn(DIR_ANGLE direction);
	void update();

	double getStopAngle();

private:
	double getVelocity();

	bool accelerating;
	Vector2D ship_vector;
	DIR_ANGLE turning_direction;
	double acceleration;
	double max_velocity;
	double turning_speed;
};

