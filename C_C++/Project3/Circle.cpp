#include "Circle.h"

Circle::Circle(Position _center, double _radius) : center(_center), radius(_radius) {
	Type = "Circle";
	area = cal_area();
}
double Circle::cal_area() {
	return SQUARE(radius) * PI;
}