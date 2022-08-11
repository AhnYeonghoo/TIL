#include "UI.h"
#include <iostream>
using namespace std;

int UI::sel1(0);
int UI::sel2(0);

void UI::printBasicUI() {
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> sel1;
}

void UI::printAddUI() {
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> sel2;
}

void UI::printSubUI() {
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> sel2;
}