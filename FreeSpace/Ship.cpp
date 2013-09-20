#include "Ship.h"


Ship::Ship(void)
{
	turning_direction = STOP;

	turning_speed = 3;
	acceleration = 0.0375;
	max_velocity = 300;

	ship_vector.x = 0;
	ship_vector.y = 0;
	accelerating = false;
}


Ship::~Ship(void)
{
}

void Ship::accelerate()
{
	accelerating = true;
}

void Ship::release()
{
	accelerating = false;
}


void Ship::turn(DIR_ANGLE dir) {
	turning_direction = dir;
}

void Ship::update()
{
	if (accelerating) {
		double radians = (PI * angle) / 180;

		Vector2D angle_vector;

		angle_vector.x = sin(radians);
		angle_vector.y = cos(radians);

		// adjust the ship's vector
		ship_vector.x += angle_vector.x * acceleration;
		ship_vector.y -= angle_vector.y * acceleration;
	} // else decelerate slightly? We'll see...
	// move the ship one unit according to it's vector
	coordinates.x += ship_vector.x;
	coordinates.y += ship_vector.y;

	setAngle(angle + turning_speed * turning_direction);
}

float Ship::getVelocity()
{
	// TODO!
	return 2;
}
