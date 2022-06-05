#include <iostream>

int main() {

    int value = 5;
    int *ptr = &value;
    std::cout << "*ptr: " << *ptr << std::endl;
    int **ptrptr = &ptr;
    std::cout << "**ptr: " << **ptrptr << std::endl;

    int *nptr = nullptr;

    int **nptrptr = nullptr;

    std::cout << "nptr: " << &nptr << std::endl;
    std::cout << "nptrptr: " << &nptrptr << std::endl;
}