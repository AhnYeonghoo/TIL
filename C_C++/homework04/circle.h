#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
//#include 
#define PI  3.14 // 원주율 전처리

// 1. 원의 넓이를 구한다.(입력은 main에서 받고) (함수1)
// 2. 넓이로 오름차순하고 오름차순하는 도중 넓이가 같으면 원의 중심좌표와 원점 길이로 오름차순한다) (함수2)
// 3. main의 함수 호출로 return



int &get_area(int repeat, int radius, int result[])
{
	
	for (int i = 0; i < repeat; i++)
	{
		result[i] = radius * radius * PI;
	}
	return *result;
}

