#include <iostream>

class A {

    public:
        A() { std::cout << "Hello A" << std::endl; }
        void show() { std::cout << "Show A" << std::endl; }
        ~A() { std::cout << "Bye A" << std:: endl; }
};

class B {

    public:
        B() { std::cout << "Hello B" << std::endl; }
        void show() { std::cout << "Show B" << std::endl; }
        ~B() { std::cout << "Bye B" << std:: endl; }
};

class C : public A, public B {
    
    public:
        C() { std::cout << "Hello C" << std::endl; }
        void show() { std::cout << "Show C" << std::endl; }
        ~C() { std::cout << "Bye C" << std::endl; }
};

int main() {
    C c;
    c.show();
    return 0;
}