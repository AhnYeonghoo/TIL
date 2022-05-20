#include <iostream>
#pragma once
struct Position {
    double x, y;
    Position(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {};
}; 

class Figure {
    protected:
        double area;

    public:
        Figure() : area(0) {}
        virtual double getArea();

        virtual ~Figure() {};
};

double Figure::getArea() {
    return this->area;
}