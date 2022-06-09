#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> vec = {100};

    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec[3]: " << vec[3] << std::endl;

    for (auto & itr : vec ) {
        std::cout << itr << " ";
    }
    std::cout << std::endl;
    return 0;
}