#include <set>
#include <iostream>
int main() {

    std::set<string> str_set = {"Hello"};
    std::multiset<string> strm_str = {"Hello"};
    str_set.insert("World");
    str_set.insert("Hello");
    str_set.erase("Hello");
    std::cout << str_set.size() << std::endl;
}