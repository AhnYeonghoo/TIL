#ifndef MYSTACK_H
#define MYSTACK_H
#include "BaseArray.h"
class MyStack : public BaseArray {
	int size;
public:
	MyStack(int n = 100) : BaseArray(n) {
		size = 0;
	};
	void push(int n) {
		put(size++, n);
	}
	int capacity() { return getCapacity(); }
	int length() { return size; }
	int pop();
};
#endif 