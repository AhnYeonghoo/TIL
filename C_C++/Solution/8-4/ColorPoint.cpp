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
	cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�ϴ� ���Դϴ�." << endl;
}