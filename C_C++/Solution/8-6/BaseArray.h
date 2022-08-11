#ifndef BASEARRAY_H
#define BASEARRAY_H

class BaseArray {
private:
	int capacity; // �迭�� ũ��
	int *mem; // ���� �迭�� ����� ���� �޸��� ������
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