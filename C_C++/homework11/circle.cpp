/* 
2021040016_컴퓨터공학과_안영후
*/
#include "circle.h"

double Circle::getRadius() {
    return this->radius;
}

double Circle::getArea() {
    return this->getRadius() * this->getRadius() * 3.141592;
}

double Circle::operator+(Figure &f) {
    return this->getArea() + f.getArea();
}

double Circle::operator-(Figure &f) {
    return this->getArea() - f.getArea();
}

double Circle::operator*(Figure &f) {
    return this->getArea() * f.getArea();
}

double Circle::operator/(Figure &f) {
    return this->getArea() / f.getArea();
}
