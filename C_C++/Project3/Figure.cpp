#include "Figure.h"

std::ostream& operator<<(std::ostream& os, Figure& a) {
	os << std::fixed;
	os.precision(2);
	os << a.area;
	os.unsetf(std::ios::fixed);
	return os;
}

double Figure::operator+(Figure& other) {
	return area + other.area;
}

double Figure::operator-(Figure& other) {
	return area - other.area;
}

double Figure::operator*(Figure& other) {
	return area * other.area;
}

double Figure::operator/(Figure& other) {
	return area / other.area;
}