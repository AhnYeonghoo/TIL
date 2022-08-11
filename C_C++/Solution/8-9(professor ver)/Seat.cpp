#include "Seat.h"
#include <string>
using namespace std;

Seat::Seat() {
	name = ""; // 빈 이름(NULL)으로 초기화해준다. 아무도 예약이 안됐음을 의미한다.
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