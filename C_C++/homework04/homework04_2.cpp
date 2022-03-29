#include <iostream>
#include <algorithm> // STL sort method 사용
#include <cmath>
#define PI 3.14


// 1. 구조체 사용(반지름, 중심좌표), 동적할당 이용
// 2. 입력 조건: 원의 개수, 원의 정보(중심좌표 및 반지름)
// 3. 정렬은 오름차순(원의 넓이가 같을 때는 원점에서 원의 중심좌표의 길이를 기준으로 오름차순)

using namespace std;

struct circle {
	float x, y, radius;
	float area;
};

int main() {
	int n; // 입력받을 원의 개수
	while (1) {
		cout << "원의 수: "; cin >> n; // 원의 개수 입력받고 아래 조건문 통해 5개 미만이면 5개 이상 요구
		if (n >= 5) break;
		else cout << "5 이상의 숫자를 입력하세요." << endl;
	}

	circle *one = new circle[n]; // 동적 메모리 할당
	
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " 번째 중심좌표와 반지름을 입력하세요" << endl; // 중심좌표 및 반지름을 입력받는다.
		cin >> one[i].x >> one[i].y >> one[i].radius; 
	}

	// 넓이 계산
	for (int i = 0; i < n; i++) {
		one[i].area = one[i].radius * one[i].radius * PI; 
	}

	// 정렬하는 부분
	for (int i = 0; i < sizeof(one->area); i++) {
		for (int j = 0; j < sizeof(one->area) - 1; j++) {
			if (one[j].area > one[j+1].area) {
				circle temp = one[j];
				one[j] = one[j + 1];
				one[j + 1] = temp; //여기까지 일반적인 정렬

				// 만약 같은 넓이가 존재한다면 원점에서 중심좌표의 길이를 기준으로 정렬  수행
				if (one[j].area == one[j + 1].area) {
					circle temp;
					float first = pow(one[j].x, one[j].y) - (one[j].y - one[j].x);
					float second = pow(one[j + 1].x, one[j + 1].y) - (one[j+1].y - one[j+1].x);
					// 구한 원점, 중심좌표의 길이를 기준으로 첫 번째가 길면 정렬
					if (first > second) {
						circle temp = one[j];
						one[j] = one[j + 1];
						one[j + 1] = temp;
					}
					// 두 번째가 길면 두 번째 기준으로 정렬
					else {
						circle temp = one[j + 1];
						one[j + 1] = one[j];
						one[j] = temp;
					}
					
				}
			} 
		}
	}

	// 최종 출력 예시에 따라 출력 수행
	for (int i = 0; i < n; i++) {
		cout << "결과: " << endl;
		cout << "(" << one[i].x << ", " << one[i].y << ")" << ", " << one[i].radius << endl;

	}
	
	
	
	
	return 0;
	
}

