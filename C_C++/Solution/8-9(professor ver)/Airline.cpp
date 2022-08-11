#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"
AirlineBook::AirlineBook(string name) {
	this->name = name;
	pSchedule = new Schedule[3]; // �� ��ü�� �⺻�����ڰ� ȣ��ȴ�.
	// �����ڰ� ȣ��Ǹ鼭 �ð��� ������ ���� ������ ���� ��޵� ��ó�� �Ű����� �ִ� �����ڴ� ���� �ʱ� ������
	// ���ε��� ��ü�� �������ش�.
	pSchedule[0].setTime("7��");
	pSchedule[1].setTime("12��");
	pSchedule[2].setTime("17��");
}

AirlineBook::~AirlineBook() {
	delete[] pSchedule;
}

void AirlineBook::run() {
	Console::msg(name + "�� ���� ���� ȯ���մϴ�.\n"); // static ����� ��ü�� ������ �ʰ� �ٷ� �θ� �� �ִ�.
	while (true) {
		int menu = Console::mainMenu();
		switch (menu) {
		case 1:	book();	break;
		case 2: cancel(); break;
		case 3: view(); break;
		case 4:
			Console::msg(name + "���� ���α׷��� �����մϴ�.");
			return;
		default:
			Console::msg("�߸� �Է��ϼ̽��ϴ�.");
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