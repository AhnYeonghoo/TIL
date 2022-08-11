#include "Schedule.h"
#include "Seat.h"
#include "Console.h"
#include <string>
using namespace std;

Schedule::Schedule() {
	pSeat = new Seat[10];
}

void Schedule::book() {
	view();
	int n = Console::getSeatNum();
	string name = Console::getName();
	n--;
	if (pSeat[n].isBooked())
		Console::msg("이미 예약된 좌석입니다.");
	else
		pSeat[n].book(name);
}

void Schedule::cancel() {
	view();
	int n = Console::getSeatNum();
	string name = Console::getName();
	n--;
	if (!pSeat[n].isBooked())
		Console::msg("예약된 좌석이 아닙니다.");
	if (!pSeat[n].checkName(name))
		Console::msg("예약자의 이름이 틀립니다.");
	pSeat[n].cancel();
}

void Schedule::view() {
	string s = "";
	for (int i = 0; i < 10; i++) {
		s += pSeat[i].toString() + "\t";
	}
	Console::msg(s);
}

Schedule::~Schedule( ) {
	delete[] pSeat;
}