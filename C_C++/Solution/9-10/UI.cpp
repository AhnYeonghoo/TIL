#include "UI.h"
#include <iostream>
using namespace std;

int UI::sel1(0);
int UI::sel2(0);

void UI::printBasicUI() {
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> sel1;
}

void UI::printAddUI() {
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> sel2;
}

void UI::printSubUI() {
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> sel2;
}