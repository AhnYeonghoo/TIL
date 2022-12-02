#include <iostream>

class Animal {
    private:
        int food;
        int weight;
    
    public:
    void setAnimal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increaseFood(int inc) {
        food += inc;
        weight += (inc / 3);
    }
    void viewStat() {
        std::cout << "food: " << food << std::endl;
        std::cout << "weight: " << weight << std::endl;
    }
};

int main() {
    Animal animal;
    animal.setAnimal(100, 50);
    animal.increaseFood(30);
    animal.viewStat();
    return 0;
}