#include "ColorPoint.h"
#include <iostream>
using namespace std;

void ColorPoint::setPoint(int x, int y) {
	move(x, y);
}
void ColorPoint::setColor(string color) { 
	this->color = color; 
}
void ColorPoint::show() {
	cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치하는 점입니다." << endl;
}