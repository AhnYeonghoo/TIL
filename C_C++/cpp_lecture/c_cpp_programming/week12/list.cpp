#include <iostream>
#include <list>

int main() {
    std::list<int> li = {100, 1, 2, 2, 3, 4, 3, 5, 5};
    li.push_back(10);
    li.push_front(99);

    std::cout << "vec size: " << li.size() << std::endl;
    
    for (auto& itr: li) {
        std::cout << itr << " ";
    }
    std::cout << std::endl;

    li.unique();
    copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}