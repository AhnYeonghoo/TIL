#include <iostream>
#include <algorithm> // STL sort method ���
#include <cmath>
#define PI 3.14


// 1. ����ü ���(������, �߽���ǥ), �����Ҵ� �̿�
// 2. �Է� ����: ���� ����, ���� ����(�߽���ǥ �� ������)
// 3. ������ ��������(���� ���̰� ���� ���� �������� ���� �߽���ǥ�� ���̸� �������� ��������)

using namespace std;

struct circle {
	float x, y, radius;
	float area;
};

int main() {
	int n; // �Է¹��� ���� ����
	while (1) {
		cout << "���� ��: "; cin >> n; // ���� ���� �Է¹ް� �Ʒ� ���ǹ� ���� 5�� �̸��̸� 5�� �̻� �䱸
		if (n >= 5) break;
		else cout << "5 �̻��� ���ڸ� �Է��ϼ���." << endl;
	}

	circle *one = new circle[n]; // ���� �޸� �Ҵ�
	
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ��° �߽���ǥ�� �������� �Է��ϼ���" << endl; // �߽���ǥ �� �������� �Է¹޴´�.
		cin >> one[i].x >> one[i].y >> one[i].radius; 
	}

	// ���� ���
	for (int i = 0; i < n; i++) {
		one[i].area = one[i].radius * one[i].radius * PI; 
	}

	// �����ϴ� �κ�
	for (int i = 0; i < sizeof(one->area); i++) {
		for (int j = 0; j < sizeof(one->area) - 1; j++) {
			if (one[j].area > one[j+1].area) {
				circle temp = one[j];
				one[j] = one[j + 1];
				one[j + 1] = temp; //������� �Ϲ����� ����

				// ���� ���� ���̰� �����Ѵٸ� �������� �߽���ǥ�� ���̸� �������� ����  ����
				if (one[j].area == one[j + 1].area) {
					circle temp;
					float first = pow(one[j].x, one[j].y) - (one[j].y - one[j].x);
					float second = pow(one[j + 1].x, one[j + 1].y) - (one[j+1].y - one[j+1].x);
					// ���� ����, �߽���ǥ�� ���̸� �������� ù ��°�� ��� ����
					if (first > second) {
						circle temp = one[j];
						one[j] = one[j + 1];
						one[j + 1] = temp;
					}
					// �� ��°�� ��� �� ��° �������� ����
					else {
						circle temp = one[j + 1];
						one[j + 1] = one[j];
						one[j] = temp;
					}
					
				}
			} 
		}
	}

	// ���� ��� ���ÿ� ���� ��� ����
	for (int i = 0; i < n; i++) {
		cout << "���: " << endl;
		cout << "(" << one[i].x << ", " << one[i].y << ")" << ", " << one[i].radius << endl;

	}
	
	
	
	
	return 0;
	
}

