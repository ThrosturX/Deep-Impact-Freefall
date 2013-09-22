#include "Starfield.h"
Starfield::Starfield(int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution( -size, size);
	// initialize the vectors
	stars = new std::vector<SDL_Point>();
	parallax = new std::vector<SDL_Point>();

	for (int i=0; i < size ; ++i) {
		SDL_Point p;
		p.x = distribution(generator);
		p.y = distribution(generator);
		stars->push_back(p);
		p.y = distribution(generator);
		p.x = distribution(generator);
		parallax->push_back(p);
	}
}

void Starfield::initialize(int size)
{

}

Starfield::~Starfield(void)
{
}

std::vector<SDL_Point> Starfield::getStarPoints()
{
	return *stars;
}

std::vector<SDL_Point> Starfield::getParallax()
{
	return *parallax;
}


std::vector<SDL_Point> Starfield::getStarPoints(SDL_Point center)
{
	SDL_Point tl = { center.x - 500, center.y - 500 };
	SDL_Point br = { center.x + 500, center.y + 500 };

	std::vector<SDL_Point> v;
	/*
	std::vector<SDL_Point>::iterator partition_end = Vector2D::start(*stars, tl, br);

	SDL_Point tl, br;
	tl.x = center.x - 500;
	tl.y = center.y - 500;
	br.x = center.x + 500;
	br.y = center.y + 500;
	*/
	SDL_Rect *view = new SDL_Rect();
	view->x = center.x - 500;
	view->y = center.y - 500;
	view->h = 1000;
	view->w = 1000;

	auto partition_end = std::stable_partition(begin(*stars), end(*stars), [view](const SDL_Point &p) { return SDL_EnclosePoints(&p, 1, NULL, view); });

//	std::vector<SDL_Point> v;

	for (std::vector<SDL_Point>::iterator p = begin(*stars); p < partition_end; ++p) {
		SDL_Point visible_star = { (int) p->x, (int) p->y };
		v.push_back(visible_star);
	}

	return v;
}