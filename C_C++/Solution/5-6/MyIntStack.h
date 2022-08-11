#ifndef MYINTSTACK_H
#define MYINTSTACK_H

#include <iostream>
using namespace std;

class MyIntStack {
	int *p; // ���� �޸𸮷� ����� ������
	int size; // ������ �ִ� ũ��
	int tos; // ������ ž�� ����Ű�� �ε���
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int &n);
};

#endif