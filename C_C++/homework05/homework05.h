#pragma once
#include <iostream>

// Ŭ���� ���� �� �ɹ��Լ��� ����

class Circle {
	
public:
	double x;
	double y;
	double area;
	double radius;
	// ����� ���� ������
	Circle(double _radius) {
		this->radius = _radius;
	}
	// �⺻������ ����
	Circle() {
		this->radius = 0;
		this->x = 0;
		this->y = 0;
		this->area = 0;
	}

	double get_area(double radius); // ���̸� ���ϴ� �޼��� 
	// void sort_area(); 
	
};