#include <iostream>

int Adder(int num1 = 1, int num2 = 2) ;

int BoxVolumn(int length, int width = 1, int height = 1);

int main(void) 
{
    std::cout << Adder() << std::endl;
    std::cout << Adder(5) << std::endl;
    std::cout << Adder(3, 5) << std::endl;
    std::cout << "[3, 3, 3] : " << BoxVolumn(3, 3, 3) << std::endl;
    std::cout << "[5, 5, 1] : " << BoxVolumn(5, 5) << std::endl;
    std::cout << "[7, 1, 1]: " << BoxVolumn(7) << std::endl;



    
    return 0;
}

int BoxVolumn(int length, int width, int height) 
{
    return length * width * height;
}

int Adder(int num1, int num2) 
{
    return num1 + num2;
}