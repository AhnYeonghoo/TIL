#include <iostream>

template<typename A, typename B>
auto sum(A a, B b) {
    return a + b;
}

template <>
auto sum<int>(int a, int b) { return a + b + 1; }

int main() {

    std::cout << sum(1, 2) <<  std::endl;
    std::cout << sum(1, 2.2)  <<std::endl;
    std::cout << sum(2.2, 2) <<std::endl;
    std::cout << sum(2.2, 4.4) <<std::endl;
}