#include <iostream>


bool IsPositive(int num);
class Animal {
    private:
        int age;
        int health;
        int attack;
        int defense;
        bool dead;

    public:
        Animal(int age, int health, int attack, int defense)
            : age(age), health(health), attack(attack), defense(defense), dead(false) {}

        int getAge(void);
        int getHealth(void);
        int getAttack(void);
        int getDefense(void);
        // bool getDead(void);
        
        void setAge(int age);
        void setHealth(int health);
        void setAttack(int attack);
        void setDefense(int defense);
        void showStatus(void);
};

int main(void)
{
    int num = 10;
    int i = 0;
    
    std::cout << "True: " << true << std::endl;
    std::cout << "False: " << false << std::endl;
    
    while (true)
    {
        std::cout << i++ << std::endl;
        if (i > num)
        {
            break; // 10번 반복한다.
        }
    }
    std::cout << std::endl;
    std::cout << "size of 1: " << sizeof(1) << std::endl; // 4byte
    std::cout << "size of false and true : " << sizeof(true) << std::endl; // True and False 1byte
    
    bool isPos;
    int num2;
    // std::cin >> num2;
    
    isPos = IsPositive(num2);
    if (isPos)
    {
        std::cout << "Positive Number " << std::endl;
    }
    else 
    {
        std::cout << "Negative Number or zero " << std::endl;
    }
    
    Animal animal(20, 100, 1000, 2000);
    animal.showStatus();
    


    return 0;
}     

bool IsPositive(int num)
{
    if (num <= 0)  return false;
    else return true;
}





void Animal::showStatus(void)
{
    std::cout << "====현재 해당 동물의 상태====" << std::endl;
    std::cout << "age: " << this->age << std::endl;
    std::cout << "health: " << this->health << std::endl;
    std::cout << "attack: " << this->attack << std::endl;
    std::cout << "defense: " << this->defense << std::endl;
    std::cout << "dead status: " << this->dead << std::endl;
    std::cout << "====End====" << "\n";
    // return EXIT_SUCCESS;
}

int Animal::getAge()
{
    return this->age;
}

int Animal::getAttack()
{
    return this->attack;
}

int Animal::getDefense()
{
    return this->defense;
}

int Animal::getHealth()
{
    return this->health;
}

void Animal::setAge(int age)
{
    this->age = age;
}

void Animal::setAttack(int attack)
{
    this->attack = attack;
}

void Animal::setDefense(int defense)
{
    this->defense = defense;
}

void Animal::setHealth(int health) 
{
    this->health = health;
}