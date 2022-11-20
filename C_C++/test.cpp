#include <iostream>
#include <string.h>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;
    
    public:
        Marine(); // default Constructor
        Marine(int x, int y); // x, y 좌표에 마린 생성
        Marine(int x, int y, const char* marine_name);
        ~Marine();
        
        int attack(); // return the damage
        void beAttacked(int damage_earn);
        void move(int x, int y);
        void showStatus();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 ! " << std::endl;
    if (name != NULL) delete[] name;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::beAttacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::showStatus() {
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location: ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    // Marine marine1(2, 3);
    // Marine marine2(3, 5);
    // marine1.showStatus();
    // marine2.showStatus();

    // std::cout << std::endl << "마린1이 마린2를 공격! "  << std::endl;
    // marine2.beAttacked(marine1.attack());
    // marine1.showStatus();
    // marine2.showStatus();

    Marine* marines[100];
    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(3, 5, "Marine 1");
    marines[0]->showStatus();
    marines[1]->showStatus();
    std::cout << std::endl << "마린1이 마린 2를 공격! " << std::endl;
    marines[0]->beAttacked(marines[1]->attack());
    marines[0]->showStatus();
    marines[1]->showStatus();
    delete marines[0];
    delete marines[1];
}
