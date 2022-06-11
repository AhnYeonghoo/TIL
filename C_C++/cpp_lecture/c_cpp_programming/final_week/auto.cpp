#include <iostream>
#include <typeinfo>

template <typename A, typename B>
decltype(auto) sum(A a, B b) {
     return a + b;
}

int main() {

    auto a = 10;
    auto b = 1.1;
    auto c = 'c';
    auto d = "string";
    auto f = 10;
    auto cpy_f = f;
    auto ref = 10;
    auto &_ref = ref;
    

    std::cout << "Type of a: " << typeid(a).name() << std::endl;
    std::cout << "Type of b: " << typeid(b).name() << std::endl;
    std::cout << "Type of c: " << typeid(c).name() << std::endl;
    std::cout << "Type of d: " << typeid(d).name() << std::endl;
    std::cout << "f: " << f << ", type of f: " << typeid(f).name() << std::endl;
    std::cout << "cpy_f: " << cpy_f << ", type of cpy_a: " << typeid(cpy_f).name() << std::endl;
    std::cout << " ref: " << ref << ", ref address: " << &ref << std::endl;
    std::cout << " _ref: " << _ref << ", _ref adress: " << &_ref << std::endl;
    std::cout << sum(a, b) << std::endl;

    return 0;
}

