#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H
#include <string>
using namespace std;
class Schedule;

class AirlineBook {
	string name;
	Schedule *pSchedule;

	void book(); // 바깥에서 부를 수 있는 건 run 뿐이고 나머지는 내부적으로 호출되는 함수들이다.
	void cancel();
	void view();
public:
	AirlineBook(string name);
	~AirlineBook();
	void run();
};


#endif