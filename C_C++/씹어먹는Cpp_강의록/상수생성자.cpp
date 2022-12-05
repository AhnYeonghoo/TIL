#include <iostream>

class Marine {
    int hp;
    int x, y;
    bool is_dead;
    const int default_damage;
    
    public:
        Marine();
        Marine(int x, int y);
        int attack();
        void BeAttacked(int damage_earn);
        void move(int x, int y);
        void ShowStatus();
};

Marine::Marine() : hp(50), x(0), y(0), default_damage(5), is_dead(false) { }
Marine::Marine(int x, int y) : x(x), y(y), hp(50), default_damage(5), is_dead(false) {}
void Marine::move(int x, int y) {
    this->x = x;
    this->y = y;
}
int Marine::attack() { return default_damage; }
void Marine::BeAttacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::ShowStatus() {
    std::cout << "*** Marine ***" << std::endl;
    std::cout << " Location : ( " << x << " , " << y << " ) " << std::endl;
    std::cout << " HP :  " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    marine1.ShowStatus();
    marine2.ShowStatus();

    std::cout << std::endl << "marine1 is attack to marine2 " << std::endl;
    marine2.BeAttacked(marine1.attack());
    marine1.ShowStatus();
    marine2.ShowStatus();
}