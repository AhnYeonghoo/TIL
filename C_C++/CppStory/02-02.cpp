#include <iostream>

int main(void)
{
    int num1 = 20;
    int& num2 = num1;

    int* num3 = &num1; // num3의 value를 num1의 주솟값으로 할당한다.
    
    std::cout << num3 << std::endl;
    std::cout << &num1 << std::endl;
    std::cout << &num2 << std::endl;
    std::cout << &num3 << std::endl; // 주솟값이 상이할 것임.

    std::cout << sizeof(num1) << std::endl;
    std::cout << sizeof(num2) << std::endl;
    std::cout << sizeof(num3) << std::endl;
    return 0;
}