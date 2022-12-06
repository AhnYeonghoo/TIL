#include <iostream>

class Marine {
    static int total_marine_num;
    
    const static int i = 0;
    
    int hp;
    int coord_x, coord_y;
    bool is_dead;
    
    const int default_damage;
    
    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, int default_damage);

        int attack() const;
        Marine& BeAttacked(int damage_earn);
        void move(int x, int y);
        
        void ShowStatus();
        static void ShowTotalMarine();
        ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;
void Marine::ShowTotalMarine() {
    std::cout << "Total Marine Number: " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
        total_marine_num++;
}

Marine::Marine(int x, int y) 
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(5),
      is_dead(false) {
        total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false)   {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() const { return default_damage; }

Marine& Marine::BeAttacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
    return *this;
}

void Marine::ShowStatus() {
    std::cout << "show status" << std::endl;
}

int main() {
    
}