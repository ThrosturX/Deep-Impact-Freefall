#include "Ship.h"

static inline void decreaseVector(Vector2D &direction) {
	static double drag = 0.0005;
	if (direction.x > 0)
		direction.x -= drag;
	else direction.x += drag;

	if (direction.y > 0)
		direction.y -= drag;
	else direction.y += drag;
}

static inline int round(double d)
{
	return static_cast<int>(d + 0.5);
}

Ship::Ship(void)
{
	turning_direction = STOP;

	turning_speed = 3;
	acceleration = 0.0575;
	max_velocity = 10;

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
	if (dir == REVERSE) {
		double targetAngle = getStopAngle();

		int a, t;

		a = round(angle);
		t = round(targetAngle);

		if (abs(a - t) < 2 || getVelocity() < 0.04) {
			turning_direction = STOP;
			return;
		}

		if (targetAngle - angle > 0)
			turning_direction = RIGHT;
		else turning_direction = LEFT;
		



	} else {
		turning_direction = dir;
	}
}

void Ship::update()
{
	if ((int)angle > 360.0)
		angle -= 360;

	else if ((int)angle < (int)0)
		angle += 360;

	if (accelerating && getVelocity() < max_velocity) {
		double radians = (PI * angle) / 180;

		Vector2D angle_vector;

		angle_vector.x = sin(radians);
		angle_vector.y = cos(radians);

		// adjust the ship's vector
		ship_vector.x += angle_vector.x * acceleration;
		ship_vector.y -= angle_vector.y * acceleration;
	} // else decelerate slightly? We'll see...
	else {
		decreaseVector(ship_vector);
	}

	// move the ship one unit according to it's vector
	coordinates.x += ship_vector.x;
	coordinates.y += ship_vector.y;

	setAngle(angle + turning_speed * turning_direction);
}

double Ship::getStopAngle()
{
	double velocityAngle = atan2(ship_vector.y, ship_vector.x);

	// convert velocityAngle to degrees
	velocityAngle *= 180 / PI;
	velocityAngle += 270;

	if (velocityAngle > 360)
		velocityAngle -= 360;

	return velocityAngle;
}

double Ship::getVelocity()
{
	double velocity = sqrt( pow(ship_vector.x, 2) + pow(ship_vector.y, 2));

	return velocity;
}
