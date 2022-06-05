#include <iostream>

int main() {
    int num = 100;
    int *ptr = &num;

    std::cout << "num: " << num << ", num address: " << &num << std::endl;
    std::cout << "*ptr: " << *ptr << ", ptr: " << ptr << ", ptr adress: " << &ptr << std::endl;

    int int_num = 1;
    float float_num = 2.4f;
    char char_c = 'a';

    int *ptr_num = &int_num;
    float *ptr_float = &float_num;
    char *ptr_c = &char_c;
    
    std::cout << &int_num << std::endl;
    std::cout << sizeof(int_num) << std::endl;
    std::cout << std::endl;
    std::cout << &float_num << std::endl;
    std::cout << sizeof(float_num) << std::endl;
    std::cout << std::endl;
    std::cout << &char_c << std::endl;
    std::cout << sizeof(char_c) << std::endl;

    std::cout << *ptr_num << ", " << ptr_num << std::endl;
    std::cout << *ptr_float << ", " << ptr_float << std::endl;
    std::cout << *ptr_c << ", " << ptr_c << std::endl;

    int *ptr2;
    int n = 100;
    ptr2 = &n;

    std::cout << &n << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << *ptr2 << std::endl;
}