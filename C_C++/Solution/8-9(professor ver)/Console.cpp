#include <iostream>
#include "Console.h"
#include <string>
using namespace std;

void Console::msg(string text) {
	cout << text << endl;
}

int Console::mainMenu() {
	cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
	int menu;
	cin >> menu;

	return menu;
}

int Console::scheduleMenu() {
	cout << "7시:1, 12시:2, 17시:3>>";
	int menu;
	cin >> menu;

	return menu;
}

int Console::getSeatNum() {
	cout << "좌석번호>>";
	int no;
	cin >> no;

	return no;
}

string Console::getName() {
	cout << "이름>>";
	string name;
	cin >> name;

	return name;
}