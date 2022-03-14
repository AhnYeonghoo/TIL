#pragma once
#include <cmath>

bool this_triangle(float a, float b, float c) { // 삼각형인지 판별하는 함수
	if (a + b > c && a + c > b && b + c > a) { 
		return true;
	}
	else {
		return false;
	}
}

float get_triangle(float a, float b, float c) {
	float s = (a + b + c) / 2.0;
	float result = sqrt(s * (s - a) * (s - b) * (s - c)); // 헤론의 공식 적용
	return result; // 결괏값 반환
}