#include <string.h>
#include <iostream>

class PhothonCannon {
    int hp, shield;
    int x, y;
    int damage;

    public:
        PhothonCannon(int x, int y);
        PhothonCannon(const PhothonCannon& pc);
    
        void ShowStatus();
};

PhothonCannon::PhothonCannon(const PhothonCannon& pc) {
    std::cout << "called copy construtor " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    x = pc.x;
    y=  pc.y;
    damage = pc.damage;
}
PhothonCannon::PhothonCannon(int x, int y) {
    std::cout << "called constructor " << std::endl;
    hp = shield = 100;
    this->x = x;
    this->y = y;
    damage = 20;
}

void PhothonCannon::ShowStatus() {
    std::cout << "Photon Cannon" << std::endl;
    std::cout << x << ", " << y << std::endl;
    std::cout << hp << std::endl;
}

int main() {
    PhothonCannon pc1(3, 3);
    PhothonCannon pc2(pc1);
    PhothonCannon pc3 = pc2;
    pc1.ShowStatus();
    pc2.ShowStatus();
    pc3.ShowStatus();
}
