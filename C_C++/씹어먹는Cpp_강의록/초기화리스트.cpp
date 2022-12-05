#include <iostream>

class Marine {
    int hp;
    int x, y;
    int damage;
    bool is_dead;

    public:
        Marine();
        Marine(int x, int y);
        
        int attack();
        void BeAttacked(int damage_earn);
        void move(int x, int y);
        
        void ShowStatus();
};

Marine::Marine() : hp(50), x(0), y(0), damage(5), is_dead(false) {}
Marine::Marine(int x, int y)
    : x(x), y(y), hp(50), damage(5), is_dead(false) {}
void Marine::move(int x, int y) {
    this->x = x;
    this->y = y;
}
int Marine::attack() { return damage; }
void Marine::BeAttacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::ShowStatus() {
    std::cout << "*** Marine ***" << std::endl;
    std::cout << " Location ( " << x << " , " << y << " ) " << std::endl;
    std::cout << " HP: " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    marine1.ShowStatus();
    marine2.ShowStatus();
}