#include <iostream>

class Marine {
    static int total_marine_num;
    
    int hp;
    int coord_x, coord_y;
    int is_dead;
    
    const int default_damage;

    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, int default_damage);

        int attack();
        void BeAttacked(int damage_earn);
        void move(int x, int y);
        void ShowStatus();

        ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_marine_num++; }
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
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::BeAttacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::ShowStatus() {
    std::cout << "Hello World" << std::endl;
    std::cout << total_marine_num << std::endl;
}

void CreateMarine() {
    Marine marine3(10, 10, 4);
    marine3.ShowStatus();
}
int main() {
    Marine marine1(2, 3, 5);

    Marine marine2(3, 5, 10);
    
    CreateMarine();

}