#include "Elementary.h"
#include "middle.h"
#include <iostream>

using namespace std;

int main()
{
	
	Person* pe = (Person*)new Elementary("¯��", 8,  "����", 1.f, "���Ϲ�");
	Person* pm = (Person*)new Middle("����", 14, "����", 1.5f, "�����а�");
	
	cout << "-��" << endl;
	
	delete pe;
	delete pm;
	return 0;
}