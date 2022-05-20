/* 
2021040016_컴퓨터공학과_안영후
*/
#pragma once
#include "figure.h"

class Circle : public Figure {
    
    private:
        double radius;

    public:
        Circle(double radius) { this->radius = radius; }
        Circle(){}
        
        double getRadius();
        double getArea();
        double operator+(Figure &f);
        double operator-(Figure &f);
        double operator*(Figure &f);
        double operator/(Figure &f);

        ~Circle(){
            std::cout << "Circle의 소멸자" << std::endl;
        }
        
};

