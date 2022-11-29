#include <iostream>

void MyFunc(void);
void MyFunc(char c);
void MyFunc(int a, int b);

int main(void) {
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);
    return EXIT_SUCCESS;
}

void MyFunc(void) {
    std::cout << "MyFunc(void) Called" << std::endl;
}

void MyFunc(char c) {
    std::cout << "MyFunc(Char c) called" << std::endl;
}
void MyFunc(int a, int b) {
    std::cout << "MyFunc(int a, int b) called" << std::endl;
}