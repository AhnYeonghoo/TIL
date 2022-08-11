#include "Stack.h"
int MyStack::pop() {
	if (size-- != 0) {
		return get(size);
	}
	return -1;
}