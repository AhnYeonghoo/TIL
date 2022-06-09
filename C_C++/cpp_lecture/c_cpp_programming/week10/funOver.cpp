#include <iostream>

int sum(int i) {
    return i + 1;
}

int sum (int i, int j) {
    return i + j;
}

int sum (int i, int j, int k ) {
    return i + j + k;
}

int main() {
    std::cout << sum(1) << std::endl;
    std::cout << sum(5, 10) << std::endl;
    std::cout << sum(10, 20, 30) << std::endl;
}