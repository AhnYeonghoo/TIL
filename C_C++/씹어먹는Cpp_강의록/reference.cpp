#include <iostream>

int ChangeVal(int *p) {
    *p = 3;

    return 0;
}

int ChangeVal2(int& p) {
    p = 2;
    return 0;
}

int main() {
    int number = 5;
    int& another_number = number;
    
    
    std::cout << number << std::endl;
    ChangeVal(&number);
    std::cout << number << std::endl;
    ChangeVal2(number);
    std::cout << number << std::endl;
    std::cout << another_number << std::endl;

    int x;
    int& y = x;
    int& z = y;
    
    x = 1;
    std::cout << x << y << z << std::endl;
    y = 2;
    std::cout << x << y << z << std::endl;
    z = 3;
    std::cout << x << y << z << std::endl;
    return 0;
}