#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int nums[500000];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int max_num = *std::max_element(nums, nums + n);

    std::cout  << max_num  << std::endl;

    return 0;
}
