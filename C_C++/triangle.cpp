#include <iostream> // 입출력을 위한 헤더파일 임포트
#include "triangle.h" // 삼각형 판별 및 넓이 구하는 함수가 있는 헤더파일 임포트
/*
int main() {
	float a, b, c; // 입력받을 세 실수
	float result; // 결괏값 저장

	while (!(std::cin.eof())) { // EOF일 때 까지 반복
		std::cout << "3개 실수를 입력하시오: ";
		std::cin >> a >> b >> c;
		if (this_triangle(a, b, c)) { // 삼각형이면 넓이 게산
			result = get_triangle(a, b, c);
			std::cout << "삼각형의 넓이는 " << result << "입니다." << std::endl;
		}
		else {
			std::cout << "삼각형이 아닙니다. 다시 입력하세요." << std::endl;
			continue; // 그냥 명시적으로 작성
		}
		
	}
	return 1;
}*/