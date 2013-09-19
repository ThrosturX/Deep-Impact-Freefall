#include "Ship.h"


Ship::Ship(void)
{
	acceleration = 0.1F;
	max_velocity = 50;

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

void Ship::update()
{
	if (accelerating) {
		float radians = (PI * angle) / 180;

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
}

float Ship::getVelocity()
{
	return 2;
}
