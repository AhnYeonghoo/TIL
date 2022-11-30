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
    std::cout << "\n\n";
    int arr[3] =  {1, 2, 3};
    
    int& ref1 = arr[0];
    int& ref2 = arr[1];
    int& ref3 = arr[2];
    
    int* ptr1 = &arr[0];
    int* ptr2 = &arr[1];
    int* ptr3 = &arr[3];
    
    std::cout << ref1 << std::endl;
    std::cout << ref2 << std::endl;
    std::cout << ref3 << std::endl;

    std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << ptr3 << std::endl;

    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;
    std::cout << *ptr3 << std::endl;

    int num = 12;
    int* ptr = &num;
    int** dptr = &ptr;
    
    int& ref = num;
    int*& pref = ptr;
    int**& dpref = dptr;
    
    std::cout << ref << std::endl;
    std::cout << *pref << std::endl;
    std::cout << **dptr << std::endl;



    return 0;
}