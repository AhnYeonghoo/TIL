#include <iostream>
#include "homework05.h"
#include <algorithm>

// 원의 개수와 중심좌표 및 반지름을 입력받는다.

using namespace std;

int main() {
	int n; // 원의 개수
	double x = 0;
	double y = 0;
	double radius = 0;
	double area = 0;

	while (true) {
		cout << "원의 개수를 입력하세요: ";
		cin >> n;
		if (n >= 5) break;
		else cout << "5개 이상 입력하세요 " << endl;
	}
	
	Circle* circle = new Circle[n]; // 객체 동적할당
	
	// 원의 정보 입력받고 get_area 메서드를 통해 넓이를 계산하여 맴버변수로 저장함.
	for (int i = 0; i < n; i++) {
		cout << "원의 중심좌표와 반지름을 입력하세요: (eg:3 4 5)";
		cin >> circle[i].x >> circle[i].y >> circle[i].radius;
	
		circle[i].area = circle[i].get_area(circle[i].radius);
		cout << endl;

	}
	
	
	// circle->sort_area(); -> 정렬 부분 구현하지 못함.
	
	
	
	// 최종 출력.
	for (int i = 0; i < n; i++) {
		cout << "원의 중심좌표와 넓이: " << "(" << circle[i].x << "," << circle[i].y << ")" << " " << circle[i].area << endl;
	}
}
