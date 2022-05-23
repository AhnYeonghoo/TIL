#include <iostream>

class Marine {

    int hp; // 마린 체력
    int coord_x, coord_y; // 마린 위치
    int damage; // 공격력
    bool is_dead;
    const int default_damage;

public:
    Marine();             // default contructor
    Marine(int x, int y); // x, y 좌표에 마린 생성

    int attack();                      // 데미지
    void be_attacked(int damage_earn); // 입는 데미지
    void move(int x, int y);           // 새로운 위치

    void show_status(); // 상태 표시
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(0), default_damage(5) , is_dead(false) {}

Marine::Marine(int x, int y)
: coord_x(x), coord_y(y), hp(50), damage(5), default_damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0)
        is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location: ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP: " << hp << std::endl;
}

class Human {
    static int total_marine_num;

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage; 

    public:
        Human();
        Human(int x, int y);
        Human(int x, int y, int default_damage);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();

        ~Human() { total_marine_num--; }
};

int Human::total_marine_num = 0;

Human::Human() : hp(50), coord_x(0), coord_y(0),  default_damage(5), is_dead(false) {
    total_marine_num++;
}

Human::Human(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Human::Human(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
    total_marine_num++;
}

void Human::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Human::attack() { return default_damage; }
void Human::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0)
        is_dead = false;
}

void Human::show_status() {
    std::cout << "*** Human *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y  << " ) " << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << " 총 인원 수: " << total_marine_num << std::endl;
}

void create_human() {
    Human human(10, 10, 4);
    human.show_status();
}

int main() {
    Human human1(2, 3, 5);
    human1.show_status();

    Human human2(3, 5, 10);
    human2.show_status();

    create_human();

    std::cout << std::endl
              << "휴먼 1이 휴먼 2를 공격! " << std::endl;
    human2.be_attacked(human1.attack());

    human1.show_status();
    human2.show_status();
}

