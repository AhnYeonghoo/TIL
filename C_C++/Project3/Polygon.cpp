#include "Polygon.h"

Polygon::Polygon(std::vector<Position>& _points) {
	Type = std::to_string(_points.size()) + "-gon";
	points = _points;
	area = cal_area();
}
double Polygon::cal_area() {
	//using CCW algorithm
	Position origin = points[0];
	double sum = 0.0;
	for (int i = 0; i < points.size(); i++) {
		sum += points[i].x * points[(i + 1) % points.size()].y - points[i].y * points[(i + 1) % points.size()].x;
	}
	return sum / 2;
}