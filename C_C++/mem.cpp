#include <iostream>

// global Variable
int a = 4;

int main() {
    int *p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list: " << list[i] << std::endl;
    }
    delete[] list;
    std::cout << a << std::endl;
    int a = 3;
    std::cout << a << std::endl;

    return 0;
}