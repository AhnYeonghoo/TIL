#include <iostream>

struct employee {
    std::string name;
    int birth_day = 19990101;
    int id;
    double score_dou = 0.0;
    char score_char = 'F';
};

int main() {

    employee park;
    park.name = "buydd";
    park.id = 2021222;

    employee lee = {"sam", 19999, 22222, 3434, 'c'};
    employee *kim;
    kim->birth_day = 20010504;
    (*kim).id = 2022123123;
    return 0;
}