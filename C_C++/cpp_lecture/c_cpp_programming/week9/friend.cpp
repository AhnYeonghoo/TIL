#include <iostream>

class Person {

    private:
        int rrn;
        
    protected:
        int money;
    
    public:
        Person(int _rrn, int _money, std::string _name) : rrn(_rrn), money(_money), name(_name){}
        ~Person(){}
        std::string name;
        friend class Friend;
};

class Friend {
    
    public:
        void showInfo(Person p) {
            std::cout << "rrn: " << p.rrn << std::endl;
            std::cout << "money: " << p.money << std::endl;
            std::cout << "name: " << p.name << std::endl;
        }
        void setInfo(Person &p, int _money) {
            p.money += _money;
        }
};

int main() {

    Person p(990101, 50000, "kim");
    Friend f;

    f.showInfo(p);
    std::cout << "\np money change" << std::endl;
    f.setInfo(p, 2000);
    f.showInfo(p);
}
