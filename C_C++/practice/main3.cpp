#include <iostream>

namespace header2 {
    void bar();
    int foo();
}

namespace header1 {
    void bar();
    int foo();
    int func() {
        foo(); 
        header2::foo(); 
    }
}


namespace {
    int OnlyInThisFile() {
        
    }
    int only_in_this_file = 0;
}

int main() {
    OnlyInThisFile();
    only_in_this_file = 3;
    std::cout << only_in_this_file << std::endl;
    std::cout << "Change the Print " << std::endl;
    int arr[2];
    arr[0] = 1;
    arr[1] = 2;
    int *parr = arr;
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << &arr << std::endl;
    std::cout << &arr[1] << std::endl;
    std::cout << *parr << std::endl;
    std::cout << parr << std::endl;
    std::cout << &parr << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    return 0;
}