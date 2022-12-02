#include <iostream>

typedef struct Animal {
    char name[30];
    int age;
    
    int health;
    int food;
    int clean;
} Animal;

void CreateAnimal(Animal *animal) {
    std::cout << "animal name?: ";
    std::cin >> animal->name;

    std::cout << "animal age?: ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void OneDayPass(Animal *animal) {
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void ShowStat(Animal *animal) {
    std::cout << animal->name << " status " << std::endl;
    std::cout << "health : " << animal->health << std::endl;
    std::cout << "food : " << animal->food << std::endl;
    std::cout << "clean : " << animal->clean << std::endl;
}

int main(void) {
    Animal *list[10];
    int animal_num = 0;

    for (;;) {
        std::cout << "1. add animal" << std::endl;
        std::cout << "2. play" << std::endl;
        std::cout << "3. show status" << std::endl;

        int input;
        std::cin >> input;
    switch (input) {
        int play_with;
        case 1:
            list[animal_num] = new Animal;
            CreateAnimal(list[animal_num]);
            animal_num++;
            break;

        case 2:
            std::cout << "누구랑 놀게? : ";
            std::cin >> play_with;

            if (play_with < animal_num) play(list[play_with]);

            break;

        case 3:
            std::cout << "누구껄 보게? : ";
            std::cin >> play_with;

            if (play_with < animal_num) ShowStat(list[play_with]);
                break;

    }
    
    for (int i = 0; i != animal_num; i++) {
        OneDayPass(list[i]);
    }
}
    for (int i = 0; i != animal_num; i++) {
        delete list[i];
    }
}