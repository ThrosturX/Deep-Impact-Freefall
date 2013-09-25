#pragma once
#include <cmath>
#include "Entity.h"
#include "di_util.h"

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
	void turn(Entity *target);
	void update();
	void disableAP();

	void setSelectedItem(Entity* item);
	Entity *getSelectedItem();
	double getStopAngle();

private:
	double getVelocity();

	bool accelerating;
	bool autopilot;
	Vector2D ship_vector;
	DIR_ANGLE turning_direction;
	double acceleration;
	double max_velocity;
	double turning_speed;
	Entity *selected_item;
};

