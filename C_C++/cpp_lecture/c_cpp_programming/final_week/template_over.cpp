#include <iostream>

template<typename T>
T const& find_max(T const& a, T const & b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

template<typename T>
T const& find_max(T const& a, T const& b, T const& c) {
    return find_max(find_max(a, b), c);
}

int main() {
    std::cout << find_max(10, 20) << std::endl;
    std::cout << find_max(10, 20, 30) << std::endl;
    std::cout << find_max(1.5, 3.4) << std::endl;
}