#include <iostream>
#include <string.h>

class PhotonCannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    char *name;

    public:
        PhotonCannon(int x, int y, const char *name);
        PhotonCannon(const PhotonCannon& pc);
        ~PhotonCannon();

        void showStatus();
};

PhotonCannon::PhotonCannon(int x, int y, const char *name) {
    std::cout << "생성자 호출! " << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

PhotonCannon::PhotonCannon(const PhotonCannon& pc) {
    std::cout << "복사 생성자 호출 ! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

PhotonCannon::~PhotonCannon() {
    if (name) delete[] name;
}

void PhotonCannon::showStatus() {
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

class Marine {

    static int total_marine_num;

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

    
    public:
        Marine(); // default Constructor
        Marine(int x, int y); // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);
        ~Marine() { total_marine_num--; }
        
        int attack(); // return the damage
        void beAttacked(int damage_earn);
        void move(int x, int y);
        void showStatus();
        
};

int Marine::total_marine_num = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y) 
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
        total_marine_num++;
    }

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
        total_marine_num++;
      }
    
void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.showStatus();
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

    PhotonCannon pc1(3, 3);
    PhotonCannon pc2(pc1);
    PhotonCannon pc3 = pc2;
    pc1.showStatus();
    pc2.showStatus();
    
}
