#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	cout << "�������� �̸��� �Է��ϼ���. ��ĭ ���� >> ";
	cin >> pName;
}

void Player::show() {
	cout << pName << " >> ";
}