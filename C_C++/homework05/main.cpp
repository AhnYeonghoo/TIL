#include <iostream>
#include "homework05.h"
#include <algorithm>

// ���� ������ �߽���ǥ �� �������� �Է¹޴´�.

using namespace std;

int main() {
	int n; // ���� ����
	double x = 0;
	double y = 0;
	double radius = 0;
	double area = 0;

	while (true) {
		cout << "���� ������ �Է��ϼ���: ";
		cin >> n;
		if (n >= 5) break;
		else cout << "5�� �̻� �Է��ϼ��� " << endl;
	}
	
	Circle* circle = new Circle[n]; // ��ü �����Ҵ�
	
	// ���� ���� �Է¹ް� get_area �޼��带 ���� ���̸� ����Ͽ� �ɹ������� ������.
	for (int i = 0; i < n; i++) {
		cout << "���� �߽���ǥ�� �������� �Է��ϼ���: (eg:3 4 5)";
		cin >> circle[i].x >> circle[i].y >> circle[i].radius;
	
		circle[i].area = circle[i].get_area(circle[i].radius);
		cout << endl;

	}
	
	
	// circle->sort_area(); -> ���� �κ� �������� ����.
	
	
	
	// ���� ���.
	for (int i = 0; i < n; i++) {
		cout << "���� �߽���ǥ�� ����: " << "(" << circle[i].x << "," << circle[i].y << ")" << " " << circle[i].area << endl;
	}
}
