#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
//#include 
#define PI  3.14 // ������ ��ó��

// 1. ���� ���̸� ���Ѵ�.(�Է��� main���� �ް�) (�Լ�1)
// 2. ���̷� ���������ϰ� ���������ϴ� ���� ���̰� ������ ���� �߽���ǥ�� ���� ���̷� ���������Ѵ�) (�Լ�2)
// 3. main�� �Լ� ȣ��� return



int &get_area(int repeat, int radius, int result[])
{
	
	for (int i = 0; i < repeat; i++)
	{
		result[i] = radius * radius * PI;
	}
	return *result;
}

