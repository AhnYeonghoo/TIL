#include <iostream>

class Test {
    int x;
    
    public:
        Test(int x) : x(x) {}
        Test(const Test& t) : x(t.x) {}
        
        Test& operator++() {
            x++;
            std::cout << "전위 증감 연산자" << std::endl;
            return *this;
        }

        Test operator++(int) {
            Test temp(*this);
            x++;
            std::cout << "후위 증감 연산자" << std::endl;
            return temp;
        }

        int GetX() const {
            return x;
        }
};

void func(const Test& t) {
    std::cout << "x: " << t.GetX() << std::endl;
}

int main() {
    Test t(3);
    func(++t);
    func(t++);
    std::cout << " x: " << t.GetX() << std::endl;
}