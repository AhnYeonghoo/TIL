#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std; // string�̶�� Ŭ������ �̸��� std namespace �ȿ� �����Ѵ�.
// class string; �Ʒ��� ���� ������ �̰͸����δ� �����ϰ� string ��������� �����ؾ� �Ѵ�.

class Seat; // �˷��ֱ⸸ �ϸ� �Ʒ��� Seat Ŭ���� �����͸� ����ϴµ� �ƹ� ������ ����.
class Schedule {
	string time; // �����Ϸ��� �� ��ü�� �����Ϸ��� �ϱ� ������, �����ڸ� �ʿ�� �Ѵ�. ������ ���� ����� ������ ������� �����ڿ� ���� ������ Ȯ���� �� ����.
	Seat *pSeat; // �����͸� �� ���� ������, ��ü�� �����ϴ� ���̱� ������ SeatŬ������ �����ڸ� ã�� �ǹǷ� Seat ��������� inlcude�ؾ� �Ѵ�.
	// ���� �����͸� ����ϴ� ���� ���α׷� �ۼ� ���߿��� ������ �� �� ���ϴ�.
public:
	Schedule();
	void setTime(string time) {
		this->time = time;
	}
	void book();
	void cancel();
	void view();
	~Schedule();
};

#endif