#pragma once

class Vector2D
{
public:
	Vector2D()
	{
		// intentionally empty
	}

	Vector2D(SDL_Point p)
	{
		x = p.x;
		y = p.y;
	}


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
	
	static std::vector<SDL_Point>::iterator start (std::vector<SDL_Point> v, SDL_Point tl, SDL_Point br)
	{
		std::vector<SDL_Point>::iterator partition_end = std::stable_partition(begin(v), end(v), [tl, br](const Vector2D &p) { return p > tl && p < br; });

		return partition_end;
	}
};
