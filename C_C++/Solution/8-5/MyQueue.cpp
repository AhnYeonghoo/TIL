#include "MyQueue.h"

void MyQueue::enqueue(int n) {
	put(last, n);
	last++;
	size = last;
}

int MyQueue::capacity() {
	return getCapacity();
}

int MyQueue::length() {
	return last;
}

int MyQueue::dequeue() {
	if (first < size) {
		val = get(first++);
		last--;
		return val;
	}
}