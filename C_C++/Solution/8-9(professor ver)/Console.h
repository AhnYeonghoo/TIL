#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
using namespace std;
class Console {
public:
	static void msg(string text); // �����͸� �ִ� ���� �ƴϹǷ�, �Ű��������� ��� ������ ȣ���� �Ͼ�� ������ ������ϰ� std namespace�� �ʿ��ϴ�.
	static int mainMenu();
	static int scheduleMenu();
	static int getSeatNum();
	static string getName();

};

#endif