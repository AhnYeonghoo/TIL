#include <iostream>
#include "homework05.h"
#define PI 3.14

using namespace std;

// Ŭ������ �ɹ��Լ� ����

double Circle::get_area(double radius) {
	return (radius * radius * PI);
}
/*
void Circle::sort_area() {

	for (int i = 0; i < sizeof(area); i++) {
		for (int j = 0; j < sizeof(area) - 1; j++) {
			if (this[j].area > this[j+1].area) {
				Circle temp = this[j].area;
				this[j].area = this[j + 1].area;
				this[j + 1].area = temp.area;
			}
		}
	}
}

*/