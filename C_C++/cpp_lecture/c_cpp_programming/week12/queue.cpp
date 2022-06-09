#include <iostream>
#include <queue>

int main() {
    std::queue<int> que;

    que.push(0);
    que.push(1);

    for (int i = 2; i < 10; i++) {
        int temp = que.front();
        std::cout << temp << " ";
        que.pop();
        que.push(temp + que.front());
    }
    return 0;
}