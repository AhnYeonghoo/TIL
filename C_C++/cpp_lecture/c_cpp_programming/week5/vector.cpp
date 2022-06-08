#include <iostream>
#include <vector>

int main() {

    std::vector<int> array;
    std::vector<int> array2 = {9, 7, 5, 3, 1};
    std::vector<int> array3{9, 7, 5, 3, 1};
    array2 = {0, 1, 2, 3, 4};
    array3 = {9, 8, 6};

    std::vector<int> array4{0, 1, 2, 3, 4};
    array4.resize(3);
    std::cout << "The Lenght is: " << array4.size() << '\n';

    for (auto const &element: array4) {
        std::cout << element << " ";
    }
}