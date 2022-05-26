// 2021040001 ½Åº¸±Ô
#include "Triangle.h"

double distance(Position& a, Position& b) {
	return std::sqrt(SQUARE(b.x - a.x) + SQUARE(b.y - a.y));
}


Triangle::Triangle(std::vector<Position>& _points) {
	Type = "Triangle";
	points = _points;
	area = cal_area();
}

double Triangle::cal_area() {
	double line[3];
	double s = 0.0;
	for (int i = 0; i < 3; i++) {
		line[i] = distance(points[i], points[(i + 1) % 3]);
		s += line[i];
	}
	s /= 2;
	return std::sqrt(s * (s - line[0]) * (s - line[1]) * (s - line[2]));
}