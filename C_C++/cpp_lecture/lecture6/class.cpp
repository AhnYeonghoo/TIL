#include <iostream>

// 클래스의 도입

/*
클래스는 variable과 method의 집합체이며 variable을 외부에서 직접 건들지 못하게 감싸는 수단을 캡슐화라고 한다.
private으로 food와 weigth 변수에 직접 접근할 수 없도록 하였다.
*/

class Animal {

    private:
        int food;
        int weigth;

        public:
        void set_animal(int _food, int _weigth) {
            food = _food;
            weigth = _weigth;
        }

        void increase_food(int inc) {
            food += inc;
            weigth += (inc / 3);
        }

        void view_stat() {
            std::cout << "이 동물의 food : " << food << std::endl;
            std::cout << "이 동물의 weigth: " << weigth << std::endl;
        }
};

int main() {

    Animal animal;
    animal.set_animal(100, 50); // setter
    animal.increase_food(30);

    animal.view_stat();

    return 0;
}