#pragma once
#include <iostream>

// 클래스 정의 및 맴버함수명만 정의

class Circle {
	
public:
	double x;
	double y;
	double area;
	double radius;
	// 사용자 정의 생성자
	Circle(double _radius) {
		this->radius = _radius;
	}
	// 기본생성자 지정
	Circle() {
		this->radius = 0;
		this->x = 0;
		this->y = 0;
		this->area = 0;
	}

	double get_area(double radius); // 넓이를 구하는 메서드 
	// void sort_area(); 
	
};