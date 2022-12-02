#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
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
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::BeAttacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::ShowStatus() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    
    marine1.ShowStatus();
    marine2.ShowStatus();
    
    std::cout << std::endl << "marine 1 is attack marine 2" << std::endl;
    marine2.BeAttacked(marine1.attack());
    marine1.ShowStatus();
    marine2.ShowStatus();
    std::cout << "\n" << "\n" << "\n";
    
    Marine* marines[100];
    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);
    marines[0]->ShowStatus();
    marines[1]->ShowStatus();
    
    std::cout << std::endl << "marines 1 is attack marines2" << std::endl;
    marines[0]->BeAttacked(marines[1]->attack());
    marines[0]->ShowStatus();
    marines[1]->ShowStatus();
    delete marines[0];
    delete marines[1];

}