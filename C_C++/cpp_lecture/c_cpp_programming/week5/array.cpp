#include <iostream>
#include <array>

void printLength(const std::array<double, 5>& my_array) {
    std::cout << "sizeOf: " << sizeof(my_array) << std::endl;
    std::cout << "length: " << my_array.size() << std::endl;
}

int main() {
    std::array<int, 3> temp_array;
    std::array<int, 5> temp_array2 = {9, 2, 4, 1, 7};
    std::array<int, 5> temp_array3{9, 2, 4, 1, 7};

    std::array<int, 5> temp_array4;
    temp_array4 = {0, 1, 2, 3, 4};

    std::cout << temp_array4[1] << std::endl;
    temp_array4[2] = 6;
    temp_array4.at(3) = 2;
    
    for (int i: temp_array4) {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::array<double, 5> my_array{9.0, 7.2, 5.4, 3.6, 1.7};
    std::cout << "Length: " << my_array.size() << std::endl;
    printLength(my_array);

    for (auto &element: my_array) {
        std::cout << element << " ";
    }
    return 0;
}