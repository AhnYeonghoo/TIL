#pragma once

#include <cmath> // ������ �Լ��� ��Ʈ �Լ� ������� ����Ʈ

float get_distance(float x1, float x2, float y1, float y2) {
	float distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	// �� �� ������ �Ÿ��� ���ϴ� ������ �״�� ���� ��

	return distance; // ����

	
}