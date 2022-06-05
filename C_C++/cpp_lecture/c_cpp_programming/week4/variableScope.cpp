#include <iostream>

int global_num; // global variable

static int static_global_num; // static global variable

int result = 0;

int sum (int x) {
    static int result = 0;
    result += x;
    return result;
}


int StaticLocalFun() {
    static int static_local_num;
    static_local_num = 10;
    global_num = 30;
    return static_local_num;
}

int main() {
    int local_num;

    global_num = 5;
    static_global_num = 10;
    local_num = 15;

    std::cout << "global num: " << global_num << std::endl;
    std::cout << "Local Num: " << local_num << std::endl;
    std::cout << "static global num: " << static_global_num << std::endl;
    int static_local_num = StaticLocalFun();

    std::cout << "global num: " << global_num << std::endl;
    std::cout << local_num << std::endl;
    std::cout << static_global_num << std::endl;
    std::cout << static_local_num << std::endl;

    for (int i = 0; i < 10; i++) {
        sum(i);
        std::cout << result << std::endl;
    }
    return 0;
}
