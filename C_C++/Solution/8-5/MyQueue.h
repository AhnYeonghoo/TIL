#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "BaseArray.h"

class MyQueue : protected BaseArray {
	int size;
	int first;
	int last;
	int val;
public:
	MyQueue(int capacity) : BaseArray(capacity) {
		first = 0;
		last = 0;
	};
	void enqueue(int n);
	int capacity();
	int length();
	int dequeue();
};

#endif
