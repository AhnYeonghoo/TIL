#include "Seat.h"
#include <string>
using namespace std;

Seat::Seat() {
	name = ""; // �� �̸�(NULL)���� �ʱ�ȭ���ش�. �ƹ��� ������ �ȵ����� �ǹ��Ѵ�.
}

void Seat::book(string name) {
	this->name = name;
}

void Seat::cancel() {
	name = "";

}

void Seat::view() {

}

bool Seat::checkName(string name) {
	if (this->name == name)
		return true;
	else
		return false;
}

string Seat::toString() {
	if (name.length() == 0)
		return "---";
	else
		return name;
}