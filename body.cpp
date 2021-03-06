// Autor: Marco Antonio Steck Filho - RA:183374

// Built-in includes
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

// Private includes
#include "body.hpp"
#include "utils.hpp"

using namespace std;

Body::Body(Vector2D speed, Vector2D position, char frame, unsigned int color){
	this->speed = speed;
	this->position = position;
	this->frame = frame;
	this->color = color;
}

void Body::setPosition(Vector2D new_position) {
	this->position = new_position;
}

void Body::setSpeed(Vector2D new_speed) {
	this->speed = new_speed;
}

Vector2D Body::getPosition() {
	return this->position;
}

Vector2D Body::getSpeed() {
	return this->speed;
}

char Body::getFrame() {
	return this->frame;
}

unsigned char Body::getColor() {
	return this->color;
}

std::ostream& operator<<(std::ostream &strm, const Body &a) {
	strm << a.color << "\n";
	strm << a.frame << "\n";
	strm << a.position << "\n";
	strm << a.speed;

	return strm;
}

std::istream& operator>>(std::istream &strm, Body &a) {
	strm >> a.color;
	strm >> a.frame;
	strm >> a.position;
	strm >> a.speed;

	return strm;
}

BodyList::~BodyList() {
	this->clear();
}

void BodyList::addBody(Body &c) {
	Body *b = new Body(c);
	this->bodies.push_back(b);
}
void BodyList::append(BodyList &bl) {
	for (Body *b: bl.getBodies()) {
		this->addBody(*b);
	}
}

void BodyList::removeAt(int i) {
	delete(this->bodies[i]);
	this->bodies.erase(this->bodies.begin()+i);
}

void BodyList::clear() {
	for (Body *body: this->bodies) {
		delete body;
	}
	this->bodies.clear();
}

std::vector<Body*> &BodyList::getBodies() {
	return this->bodies;
}

std::ostream& operator<<(std::ostream &strm, const BodyList &a) {
	strm << a.bodies.size() << "\n";

	for (std::vector<Body *>::size_type i=0; i < a.bodies.size(); i++) {
		if (i != a.bodies.size()-1) {
			strm << *a.bodies[i] << "\n";
		} else {
			strm << *a.bodies[i];
		}
	}

	return strm;
}

std::istream& operator>>(std::istream &strm, BodyList &a) {
	a.clear();

	std::vector<Body *>::size_type size = 0;
	strm >> size;

	for (std::vector<Body *>::size_type i = 0; i < size; i++) {
		Body b(Vector2D(), Vector2D(), 0, 0);
		strm >> b;
		a.addBody(b);
	}

	return strm;
}
