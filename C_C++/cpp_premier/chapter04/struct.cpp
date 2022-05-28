#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {

    inflatable *ps = new inflatable;
    std::cout << "모형 풍선의 이름을 입력하시오: ";
    std::cin.get(ps->name, 20);
    std::cout << "부피를 세제곱 피트 단위로 입력하십시오: ";
    std::cin >> (*ps).volume;
    std::cout << "가격을 달러 단위로 입력하십시오: $";
    std::cin >> ps->price;
    std::cout << "이름: " << (*ps).name << std::endl;
    std::cout << "부피: " << ps->volume << std::endl;
    std::cout << "가격: " << ps->price << std::endl;
    delete ps;
    return 0;
}