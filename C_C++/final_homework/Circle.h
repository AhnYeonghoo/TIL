// 2021040016_¾È¿µÈÄ
#pragma once
#include "Figure.h"

class Circle : public Figure {
	Position center;
	double radius;
public:
	Circle(Position _center, double _radius);
	double cal_area();
};