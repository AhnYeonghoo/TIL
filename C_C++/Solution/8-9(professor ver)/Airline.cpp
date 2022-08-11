#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"
AirlineBook::AirlineBook(string name) {
	this->name = name;
	pSchedule = new Schedule[3]; // 각 객체당 기본생성자가 호출된다.
	// 생성자가 호출되면서 시간을 셋팅할 수도 있지만 위에 언급된 것처럼 매개변수 있는 생성자는 돌지 않기 때문에
	// 따로따로 객체를 생성해준다.
	pSchedule[0].setTime("7시");
	pSchedule[1].setTime("12시");
	pSchedule[2].setTime("17시");
}

AirlineBook::~AirlineBook() {
	delete[] pSchedule;
}

void AirlineBook::run() {
	Console::msg(name + "에 오신 것을 환영합니다.\n"); // static 멤버는 객체를 만들지 않고 바로 부를 수 있다.
	while (true) {
		int menu = Console::mainMenu();
		switch (menu) {
		case 1:	book();	break;
		case 2: cancel(); break;
		case 3: view(); break;
		case 4:
			Console::msg(name + "예약 프로그램을 종료합니다.");
			return;
		default:
			Console::msg("잘못 입력하셨습니다.");
		}
	}
}

void AirlineBook::book() {
	int n = Console::scheduleMenu();
	n--;
	pSchedule[n].book();
}

void AirlineBook::cancel() {
	int n = Console::scheduleMenu();
	n--;
	pSchedule[n].cancel();
}

void AirlineBook::view() {
	for (int i = 0; i < 3; i++) {
		pSchedule[i].view();
	}
}