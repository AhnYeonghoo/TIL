#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std; // string이라는 클래스의 이름은 std namespace 안에 존재한다.
// class string; 아래의 이유 때문에 이것만으로는 부족하고 string 헤더파일을 포함해야 한다.

class Seat; // 알려주기만 하면 아래의 Seat 클래스 포인터를 사용하는데 아무 문제가 없다.
class Schedule {
	string time; // 컴파일러가 이 객체를 생성하려고 하기 때문에, 생성자를 필요로 한다. 하지만 위에 선언된 구문만 가지고는 생성자에 대한 정보를 확인할 수 없다.
	Seat *pSeat; // 포인터를 써 주지 않으면, 객체를 생성하는 것이기 때문에 Seat클래스의 생정자를 찾게 되므로 Seat 헤더파일을 inlcude해야 한다.
	// 따라서 포인터를 사용하는 것이 프로그램 작성 도중에서 보더라도 좀 더 편리하다.
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