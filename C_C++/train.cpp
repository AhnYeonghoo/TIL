#include <iostream>

// Chapter 3. 참조자의 도입

int change_val(int *p) {
    *p = 3;
    return 0;
}
int changeValRef(int &p) {
    p = 7;
    return 0;
}
int changeValRef2(int &p) {
    p = 10;
    return 0;
}
int &function(int &a) {
    a = 5;
    return a;
}
int main() {
    int number = 5;
    int &anohter_number = number;
    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;
    std::cout << number << std::endl;
    std::cout << anohter_number << std::endl;
    changeValRef(anohter_number);
    std::cout << number << std::endl;
    changeValRef2(number);
    std::cout << number << std::endl;
    std::cout << anohter_number << std::endl;
    int x;
    int &y = x; // y는 x의 또 다른 별명
    int &z = y; // z는 y의 또 다른 별명
    // 근데 y는 x의 별명이므로 결과적으로 z는 -> y -> x를 가리킴
    x = 1;
    std::cout << x << y << z << std::endl;
    y = 2;
    std::cout << x << y << z << std::endl;
    z = 3;
    std::cout << x << y << z << std::endl;
    // 하지만 위 예시처럼 참조자의 참조자를 만드는 것은 금기시 되어 있다. (사용 지양)
    system("cls");
    int b = 2;
    int c = function(b);
    std::cout << b << c << std::endl;
    return 0;
}