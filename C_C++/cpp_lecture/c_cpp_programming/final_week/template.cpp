#include <iostream>

// void swap(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void swap(double &a, double &b) {
//     double temp = a;
//     a = b;
//     b = temp;
// }

// void swap (char &a, char &b) {
//     char temp = a;
//     a = b;
//     b = temp;
// }

// void swap(std::string &a, std::string &b) {
//     std::string temp = a;
//     a = b;
//     b = temp;
// }

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename A, typename B>
auto sum(A a, B b) {
    return a + b;
}

int main() {

    int n1 = 10, n2 = 20;
    double d1 = 1.1, d2 = 3.3;
    char c1 = 'a', c2 = 'e';
    std::string s1 = "Hello", s2 = "Bye";

    std::cout << "Before" << std::endl;
    std::cout << "n1: " << n1 << ", n2: " << n2;
    std::cout << "d1: " << d1 << ", d2 : " << d2;
    std::cout << "c1: " << c1 << ", c2: " << c2;
    std::cout << "s1: " << s1 << ", s2: " << s2;

    std::cout << "\n===================" << std::endl;
    std::cout << "swap" << std::endl;
    swap(n1, n2);
    swap(d1, d2);
    swap(c1, c2);
    swap(s1, s2);

    std::cout << "---------------------" << std::endl;
    std::cout << "After" << std::endl;
    std::cout << "n1: " << n1 << ", n2: " << n2;
    std::cout << "d1: " << d1 << ", d2: " << d2;
    std::cout << "c1: " << c1 << ", c2: " << c2;
    std::cout << "s1: " << s1 << ", s2: " << s2;

    std::cout << "\n\n"
              << std::endl;
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1, 2.2) << std::endl;
    std::cout << sum(2.2, 2) << std::endl;
    std::cout << sum(2.2, 4.4) << std::endl;
}