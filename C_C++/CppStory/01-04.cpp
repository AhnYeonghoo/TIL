#include <iostream>

#define SQUARE(x) ((x) * (x))

inline int SQUARE2(int x) 
{
    return x * x;
}

template <typename T>
inline T SQUARE3(T x) 
{
    return x * x;
}

int main(void)
{
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(2.7) << std::endl;
    std::cout << SQUARE2(7.15) << std::endl;
    std::cout << SQUARE3(5) << std::endl;
    std::cout << SQUARE3(7.154) << std::endl;
}