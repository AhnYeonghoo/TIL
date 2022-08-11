#include "Shape.h"

Shape::Shape() {
	next = nullptr;
}

Shape::~Shape() { }

void Shape::paint() { 
	draw(); 
}

Shape* Shape::add(Shape *p) {
	this->next = p;
	return p;
}

Shape* Shape::getNext() { 
	return next; 
}