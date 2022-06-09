#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq = {100};
    for (int i = 0; i < 10; i++) {
        deq.push_back(i);
    }
    deq.push_front(99);
    std::cout << "vec size: " << deq.size() << std::endl;
    std::cot << "vec[3]: " << deq[3] << std::endl;

    for (auto& itr: deq) {
        std::cout << itr << std::endl;
    }
    std::endl;

}