#include <string.h>

#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;
    
    public:
        Marine();
        Marine(int x, int y, const char* marine_name);
        Marine(int x, int y);
        ~Marine();
        
        int attack();
        void BeAttacked(int damage);
        void move(int x, int y);
        void ShowStatus();
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
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
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::~Marine() { 
    std::cout << name << " destructor " << std::endl;
    if (name != NULL) delete[] name;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::BeAttacked(int damage) {
    hp -= damage;
    if (hp <= 0) is_dead = true;
}
void Marine::ShowStatus() {
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
    << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine* marines[100];
    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");
    marines[0]->ShowStatus();
    marines[1]->ShowStatus();
    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marines[0]->BeAttacked(marines[1]->attack());
    marines[0]->ShowStatus();
    marines[1]->ShowStatus();
    delete marines[0];
    delete marines[1];

}