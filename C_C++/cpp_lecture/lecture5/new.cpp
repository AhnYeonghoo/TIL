#include <iostream>

int main() {
    
    // 자유롭게 메모리를 할당하고 해제할 수 있는 메모리 공간 == Heap
    // 기존의 함수, 일반변수 등과 같은 것들이 쌓이는 메모리 공간 == Stack

    int *p = new int;
    *p = 10;

    std::cout << *p << std::endl;
    delete p;

    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;
    int *list = new int[arr_size]; // 동적으로 배열의 크기를 할당할 수 있음.
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }

    for (int i = 0; i < arr_size; i ++) {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }

    delete[] list;

    return 0;
}