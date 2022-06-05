#include <iostream>
#include <typeinfo>

#define PI 3.14
#define STR "Hello STR~"
#define DOUBLE(x) (x*x)
const int MAX = 100;


int main() {
    std::cout << "PI: " << PI << ", type: " << typeid(PI).name() << std::endl;
    std::cout << "STR: " << STR << ", type: " << typeid(STR).name() << std::endl;
    std::cout << "DOUBLE 2: " << DOUBLE(2) << std::endl;

    int value = 3, value2 = 7;
    const int *ptr = &value; // not change value
    value = 5;
    std::cout << "value: " << value << ", *ptr: " << *ptr << ", ptr: " << ptr << std::endl;
    value = 7;
    ptr = &value2;
    std::cout << "value: " << value << ", *ptr: " << *ptr << ", ptr: " << ptr << std::endl;

    int *const  ptr2 = &value; // not change adress
    *ptr2 = 5;
    std::cout << "value: " << value << ", *ptr2: " << *ptr2 << ", ptr2: " <<*ptr2<< std::endl;
    value = 7;
    std::cout << "value: " << value << ", *ptr2: " << *ptr2 << ", ptr:2 " << ptr2 << std::endl;
    int v = 3;
    const int *ptr1 = &v; // 주소 변경 가능, 값 불가능 
    int *const ptr2 = &v // 주소 변경 불가능, 값 가능
    const int* const ptr3 = &value // 주소, 값 모두 변경 불가능
    return 0;
}