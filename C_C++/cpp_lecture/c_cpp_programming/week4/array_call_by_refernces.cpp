#include <iostream>

int main() {

    int array[] = {1, 2, 3, 4, 5};
    
    for (int data: array) {
        data = data * 5;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << array[i] << std::endl;
    }

    std::cout << "------------------\n";
    for (int &data: array) {
        data = data * 5;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << array[i] << std::endl;
    }
}