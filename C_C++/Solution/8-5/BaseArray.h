#ifndef BASEARRAY_H
#define BASEARRAY_H

class BaseArray {
private:
	int capacity; // 배열의 크기
	int *mem; // 정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray::BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray();
	void put(int index, int val);
	int get(int index);
	int getCapacity();
};
#endif