#include <iostream>
#include "Console.h"
#include <string>
using namespace std;

void Console::msg(string text) {
	cout << text << endl;
}

int Console::mainMenu() {
	cout << "����:1, ���:2, ����:3, ������:4>>";
	int menu;
	cin >> menu;

	return menu;
}

int Console::scheduleMenu() {
	cout << "7��:1, 12��:2, 17��:3>>";
	int menu;
	cin >> menu;

	return menu;
}

int Console::getSeatNum() {
	cout << "�¼���ȣ>>";
	int no;
	cin >> no;

	return no;
}

string Console::getName() {
	cout << "�̸�>>";
	string name;
	cin >> name;

	return name;
}