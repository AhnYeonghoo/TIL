#pragma once
#include <cmath>

bool this_triangle(float a, float b, float c) { // �ﰢ������ �Ǻ��ϴ� �Լ�
	if (a + b > c && a + c > b && b + c > a) { 
		return true;
	}
	else {
		return false;
	}
}

float get_triangle(float a, float b, float c) {
	float s = (a + b + c) / 2.0;
	float result = sqrt(s * (s - a) * (s - b) * (s - c)); // ����� ���� ����
	return result; // �ᱣ�� ��ȯ
}