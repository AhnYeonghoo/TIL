#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
using namespace std;
class Console {
public:
	static void msg(string text); // 포인터를 주는 것이 아니므로, 매개변수명이 없어도 생성자 호출이 일어나기 때문에 헤더파일과 std namespace가 필요하다.
	static int mainMenu();
	static int scheduleMenu();
	static int getSeatNum();
	static string getName();

};

#endif