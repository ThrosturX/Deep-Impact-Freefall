#include "Starscape.h"


Starscape::Starscape(Window* win, SDL_Point *displacement)
{
	window = win;
	area = win->getBox();

	direction = displacement;

	num_images = 9;

	images = new Image[num_images];

	// load images
	images[0].open("res/star.png", window->getRenderer());
	images[1].open("res/star_far.png", window->getRenderer());
	images[2].open("res/star2.png", window->getRenderer());
	images[3].open("res/star3.png", window->getRenderer());
	images[4].open("res/star3_far.png", window->getRenderer());
	images[5].open("res/star4.png", window->getRenderer());
	images[6].open("res/star5.png", window->getRenderer());
	images[7].open("res/star_far0.png", window->getRenderer());
	images[8].open("res/star_far1.png", window->getRenderer());

	horizontal = new std::uniform_int_distribution<int>(-(area.w), area.w);
	vertical   = new std::uniform_int_distribution<int>(-(area.h), area.h);
	layering   = new std::uniform_real_distribution<double>(0.10, 0.35);

	// seed... for now
	generator.seed(generator.default_seed);

	// add some random stars
	for (int i=0; i < 100; ++i) {
		// create the star
		Star *star = new Star();
		star->file = images[i % num_images];
		star->pos.x = (*horizontal)(generator);
		star->pos.y = (*vertical)(generator);
		star->layer = (*layering)(generator);
		// add it to the data collection
		stars.push_back(*star);
	}
}


Starscape::~Starscape(void)
{
}

void Starscape::draw()
{
	int w = area.w;
	int h = area.h;
	int w2 = w/2;
	int h2 = h/2;
	
	for (std::deque<Star>::iterator it = begin(stars); it != end(stars); ++it) {
		// displace stars with ship
		int displx(static_cast<int>(direction->x * it->layer)),
			disply(static_cast<int>(direction->y * it->layer));

		int x(it->pos.x),
			y(it->pos.y);

		SDL_Point loc =
			{ static_cast<int> (displx - x)
			, static_cast<int> (disply - y)
		};

		// ensure there are always stars on-screen
		int diff;
		
		if ((diff = displx - x) > area.w) {
			it->pos.x += area.w * 2;
			it->pos.y += static_cast<int>(0.5 * (*vertical)(generator));
			it->file = images[abs(y) % num_images];
		} // pos.y and file changed to increase "randomness"

		if (diff                < -area.w) {
			it->pos.x -= area.w * 2;
			it->pos.y += static_cast<int>(0.5 * (*vertical)(generator));
			it->file = images[abs(y) % num_images];
		}

		if ((diff = disply - y) > area.h) {
			it->pos.y += area.h * 2;
			it->pos.x += static_cast<int>(0.5 * (*horizontal)(generator));
			it->file = images[abs(x) % num_images];
		}

		if (diff                < -area.h) {
			it->pos.y -= area.h * 2;
			it->pos.x += static_cast<int>(0.5 * (*horizontal)(generator));
			it->file = images[abs(y) % num_images];
		}

		// draw the damn thing
		window->draw(&(it->file), loc);
	}
}