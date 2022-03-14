#pragma once

#include <cmath> // 제곱근 함수와 루트 함수 사용위해 임포트

float get_distance(float x1, float x2, float y1, float y2) {
	float distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	// 두 점 사이의 거리를 구하는 공식을 그대로 적용 후

	return distance; // 리턴

	
}