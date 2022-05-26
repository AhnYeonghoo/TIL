// 2019037027_¹ÚÁ¤Çö
#pragma once
#include <string>
#include <iostream>
#include <cmath>
#define SQUARE(x) (x)*(x)

const double PI = 3.141592;

struct Position {
	double x;
	double y;
	Position(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
};

class Figure {
protected:
	double area;
	std::string Type;
public:
	Figure() : area(0) {}
	virtual double cal_area() = 0;
	std::string type() {
		return Type;
	}
	double operator+(Figure& other);
	double operator-(Figure& other);
	double operator*(Figure& other);
	double operator/(Figure& other);
	friend std::ostream& operator<<(std::ostream& os, Figure& a);
};