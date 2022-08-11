#include "BaseArray.h"

BaseArray::~BaseArray() {
	delete[] mem;
}

void BaseArray::put(int index, int val) {
	mem[index] = val;
}
int BaseArray::get(int index) {
	return mem[index];
}

int BaseArray::getCapacity() {
	return capacity;
}