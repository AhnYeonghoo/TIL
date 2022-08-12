#include <iostream>
#include <vector>

int main() {
    // initialization
    std::vector<int> number;
    int sum = 0;
    bool flag = false;

    // input the number
    for (int i = 0; i < 9; i++) {
        int temp;
        std::cin >> temp;
        number.push_back(temp);
    }

    for (int i : number) {
        sum += i;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - number[i] - number[j] == 100) {
                number[i] = 0;
                number[j] = 0;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    for (int i = 0; i < 9; i++) {
        if (number[i] != 0) {
            std::cout << number[i] << '\n';
        }
    }
    return 0;
}
