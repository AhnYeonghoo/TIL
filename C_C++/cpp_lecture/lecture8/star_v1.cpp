#include <iostream>
#include <string>

class PhotonCannon {
    private:
        int hp, shield;
        int coord_x, coord_y;
        int damage;

    public:
        PhotonCannon(int x, int y);
        PhotonCannon(const PhotonCannon &pc);
        ~PhotonCannon();

        void show_status();
};

PhotonCannon::PhotonCannon(const PhotonCannon& pc) {
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
PhotonCannon::PhotonCannon(int x, int y) {
    std::cout << " 생성자 호출! " << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
void PhotonCannon::show_status() {
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << "HP : " << hp << std::endl;
}
PhotonCannon::~PhotonCannon() {
    std::cout << " 소멸자  실행 !" << std::endl;
}


class Marine {
    
    private:
        int hp; // 체력
        int coord_x, coord_y; // 위치
        int damage; // 공격력
        bool is_dead;
        std::string name;

    public:
        Marine();             // 기본생성자
        Marine(int x, int y, std::string marine_name);
        Marine(int x, int y); // x, y좌표에 마린 생성
        ~Marine();

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y, std::string marine_name) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = marine_name;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = "";
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0)
        is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine : "<< name << " *** " <<  std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP: " << hp << std::endl;
}

Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출! " << std::endl;
    
}

int main() {

    // Marine marine1(2, 3);
    // Marine marine2(3, 5);

    // marine1.show_status();
    // marine2.show_status();

    // std::cout << std::endl
    //           << "마린1이 마린2를 공격! " << std::endl;
    // marine2.be_attacked(marine1.attack());

    // marine1.show_status();
    // marine2.show_status();

    // Marine* marine[100];
    // marine[0] = new Marine(2, 3);
    // marine[1] = new Marine(3, 5);

    // marine[0]->show_status();
    // marine[1]->show_status();

    // std::cout << std::endl
    //           << "마린 1이 마린 2를 공격! " << std::endl;
    // marine[0]->be_attacked(marine[1]->attack());
    // marine[0]->show_status();
    // marine[1]->show_status();

    // delete marine[0];
    // delete marine[1];

    Marine *marines[100];

    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << "\n마린 1이 마린 2를 공격!" << std::endl;

    marines[0]->be_attacked(marines[1]->attack());
    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];

    PhotonCannon pc1(3, 3);
    PhotonCannon pc2(pc1);
    PhotonCannon pc3 = pc2;

    pc1.show_status();
    pc2.show_status();
    return 0;
}