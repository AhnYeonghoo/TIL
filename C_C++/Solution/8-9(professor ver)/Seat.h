#ifndef SEAT_H
#define SEAT_H
#include <string>
using namespace std;

class Seat {
	string name;
public:
	Seat(); // Schedule() 생성자 함수에서 Seat객체를 배열로 동적생성하기 때문에, 기본생성자를 만들어줘야함을 알 수 있다.
	void book(string name);
	bool isBooked() { return name.length() == 0 ? false : true; }
	void cancel();
	void view();
	bool checkName(string name); // 맞으면 true
	string toString();
	// 소멸자가 할 역할이 특별히 보이지 않기 때문에 당장 만들어 두진 않았다.
};

#endif