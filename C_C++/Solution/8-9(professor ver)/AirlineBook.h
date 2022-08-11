#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H
#include <string>
using namespace std;
class Schedule;

class AirlineBook {
	string name;
	Schedule *pSchedule;

	void book(); // �ٱ����� �θ� �� �ִ� �� run ���̰� �������� ���������� ȣ��Ǵ� �Լ����̴�.
	void cancel();
	void view();
public:
	AirlineBook(string name);
	~AirlineBook();
	void run();
};


#endif