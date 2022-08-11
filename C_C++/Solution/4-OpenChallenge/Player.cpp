#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	cout << "참가자의 이름을 입력하세요. 빈칸 없이 >> ";
	cin >> pName;
}

void Player::show() {
	cout << pName << " >> ";
}