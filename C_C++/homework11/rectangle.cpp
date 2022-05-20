#include "rectangle.h"

double Rectangle::getWidth() {
    return this->position[1].x - this->position[0].x;
}
double Rectangle::getHeight() {
    return this->position[1].y - this->position[0].y;
}
double Rectangle::getArea() {
    return this->getWidth() * this->getHeight();
}