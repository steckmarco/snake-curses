#include <cstdlib>
#include <ctime>

#include "ncurses.h"

#include "food.hpp"

Food::Food(int maxX, int maxY, unsigned char color) {
	this->maxX = maxX;
	this->maxY = maxY;
	this->color = color;
	std::srand(std::time(NULL));
	spawn();
}

void Food::spawn() {
	int x, y;
	x = 1 + std::rand()%(this->maxX-2);
	y = 1 + std::rand()%(this->maxY-2);
	Body new_food(Vector2D(0,0), Vector2D(x, y), FOOD_CHAR, this->color);
	this->addBody(new_food);
}

void Food::despawnIndex(int i) {
	this->removeAt(i);
}

int Food::getNumFood() {
	return this->getBodies().size();
}
