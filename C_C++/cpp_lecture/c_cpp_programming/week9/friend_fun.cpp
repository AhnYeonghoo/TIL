#include <iostream>

class Person {

    private:
        int rrn;

    protected:
        int money;

    public:
        Person(int r, int m, std::string n):rrn(r), money(m), name(n){}
        ~Person(){}
        std::string name;
        friend void showInfo(Person p);
        friend void setInfo(Person &p, int m);
};

void showInfo(Person p) {
    std::cout << "rrn: " << p.rrn << std::endl;
    std::cout << "money: " << p.money << std::endl;
    std::cout << "name: " << p.name << std::endl;
}
void setInfo(Person &p, int m) {
    p.money += m;
}

int main() {
    Person p(991111, 200000, "Park");
    showInfo(p);
    std::cout << "p money change" << std::endl;
    setInfo(p, 5000);
    showInfo(p);
}