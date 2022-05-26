#pragma once
#include "Figure.h"
#include <vector>

class Polygon : public Figure {
	std::vector<Position> points;
public:
	Polygon(std::vector<Position>& _points);
	double cal_area();
};