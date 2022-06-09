#include <iostream>
#include <forward_list>

int main() {

    std::forward_list<int> li = {
        100,
        1,
        2,
        3,
        4,
        4,
        5,
        3
    };
    li.push_front(99);
    for (auto & itr : li) {
        std::cout << itr << " ";
    }
    std::cout << std::endl;
    li.unique();
    copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
    li.remove(3);
    copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}