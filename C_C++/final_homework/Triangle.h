// 2021040001 ½Åº¸±Ô
#pragma once
#include "Figure.h"
#include <vector>

double distance(Position& a, Position& b);

class Triangle : public Figure {
	std::vector<Position> points;
public:
	Triangle(std::vector<Position>& _points);
	double cal_area();
};