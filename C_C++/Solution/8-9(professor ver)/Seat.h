#ifndef SEAT_H
#define SEAT_H
#include <string>
using namespace std;

class Seat {
	string name;
public:
	Seat(); // Schedule() ������ �Լ����� Seat��ü�� �迭�� ���������ϱ� ������, �⺻�����ڸ� ������������ �� �� �ִ�.
	void book(string name);
	bool isBooked() { return name.length() == 0 ? false : true; }
	void cancel();
	void view();
	bool checkName(string name); // ������ true
	string toString();
	// �Ҹ��ڰ� �� ������ Ư���� ������ �ʱ� ������ ���� ����� ���� �ʾҴ�.
};

#endif