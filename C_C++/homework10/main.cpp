#include <iostream>
#include "overloading.h"

int main() {

	Point p1(20, 20);
	Point p2(50, 70);
	
	p1.operator++();
	p1.pPrint();
	p1.operator*(p2);
	p2.pPrint();
	std::cout << p2.operator<(p1) << std::endl;
	std::cout << p2.operator>(p1) << std::endl;


	return 0;
}