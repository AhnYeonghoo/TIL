#pragma once
#include <cmath>
#include <iostream>
#include <string>

class Point {
	int x, y;

public:
	Point(int _x, int _y): x(_x), y(_y) {}
	Point() {
		this->x = 0;
		this->y = 0;
	}
	
	friend bool operator== (const Point& x, const Point& y) {
		return x.x == y.y;
	}

	bool operator < (const Point& p) {
		return this->x < p.x;
	}
	
	bool operator <= (const Point& p) {
		return this->x <= p.x;
	}
	
	bool operator > (const Point& p) {
		return this->x > p.x;
	}
	
	bool operator >= (const Point& p) {
		return this->x >= p.x;
	}
	
	operator double() const {
		return double(x) / double(y);
	}
		
	Point operator* (const Point& p) {
		Point temp;
		temp.x = p.x * this->x;
		return temp;
	}

	Point& operator++() {
		x += 1;
		y += 1;
		return *this;
	}

	Point& operator--() {
		x -= 1;
		y -= 1;
		return *this;
	}

	Point& operator++(int) {
		x += 1;
		y += 1;
		return *this;
	}
	
	void pPrint() {
		std::cout << "x: " << x << ", y :" << y << std::endl;
	}
	~Point(){}





	
	

	
};