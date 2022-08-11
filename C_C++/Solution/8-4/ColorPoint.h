#ifndef COLORPOINT_H
#define COLORPOINT_H
#include "Point.h"
#include <string>
using namespace std;

class ColorPoint : protected Point {
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) {
		this->color = color;
	}
	void setPoint(int x, int y);
	void setColor(string color);
	void show();
};
#endif