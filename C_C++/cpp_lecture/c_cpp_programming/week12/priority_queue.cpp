#include <iostream>
#include <queue>

int main() {

    std::priority_queue<int> pq;
   
    for (const int n : {1, 8 , 5, 6, 3, 4, 0 ,9, 7, 2}) {
        pq.push(n);
    }
    for (int i = 0; i < 10; i++) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
    return 0;
}