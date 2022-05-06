#include "Elementary.h"
#include "middle.h"
#include <iostream>

using namespace std;

int main()
{
	
	Person* pe = (Person*)new Elementary("炉备", 8,  "货较", 1.f, "货较馆");
	Person* pm = (Person*)new Middle("绕捞", 14, "楷滴", 1.5f, "楷滴切苞");
	
	cout << "-场" << endl;
	
	delete pe;
	delete pm;
	return 0;
}