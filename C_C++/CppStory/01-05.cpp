#include <iostream>

namespace Company1 
{
    void func(void) 
    {
        std::cout << "Company1 이 정의한 함수 " << "\n";
    }
    void hello(void);
}

namespace Company2 
{
    void func(void)
    {
        std::cout << "Company2 이 정의한 함수 " << "\n";
    }
}

namespace Parent 
{
    int num = 0;
    namespace sun 
    {
        int num = 1;
    }
    namespace Daughter
    {
        int num = 2;
    }
}

namespace AAA 
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int val = 100;

int main(void) 
{
    Company1::func();
    Company2::func();
    std::cout << Parent::num << std::endl;
    std::cout << Parent::sun::num << std::endl;

    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;
    namespace ABC = AAA::BBB::CCC;
    std::cout << ABC::num1 << std::endl;
    std::cout << ABC::num2 << std::endl;
    std::cout << "\n";
    int val = 20;
    val += 3;
    ::val += 10;
    std::cout << "local variable: " << val << std::endl;
    std::cout << "global variable: " << ::val << std::endl;
    return 0;
}

void Company1::hello(void)
{
    std::cout << "hello " << std::endl;
}