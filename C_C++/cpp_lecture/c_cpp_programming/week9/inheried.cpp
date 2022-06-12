#include <iostream>
 
// 상위클래스
class Person {

    private:
        int rrn; // 주민번호
        
    protected:
        int money;

    public:
        std::string name;
        void setRrn(int _rrn);
        void setMoney(int _money);
        void setName(std::string _name);
        int getRrn();
        int getMoney();
        std::string getName();
};


// 하위클래스
class Student : protected Person {

    private:
        int pinm; // 용돈
        
    protected:
        int grades; 
    
    public:
        std::string grade;
        void pModify(int r, int m, std::string n);
        void setPinm(int p);
        int getPinm();
        void setGrades(int g);
        int getGrades();
        
};

int main() {

    Person p;
    p.setRrn(990403);
    p.setMoney(1000);
    p.name = "Ahn";

    std::cout << "basic class Person p " << std::endl;
    std::cout << p.getRrn() << std::endl;
    std::cout << p.getMoney() << std::endl;
    std::cout << p.name << std::endl;

    Student s;
    s.pModify(990202, 2000, "park");
    s.setPinm(5000);
    s.setGrades(60);
    s.grade = "2nd";
    std::cout << "derived class Student s" << std::endl;
    std::cout << s.getGrades() << std::endl;
    std::cout << s.grade << std::endl;
    std::cout << s.getPinm() << std::endl;
    return 0;
}


void Person::setRrn(int _rrn) {
    this->rrn = _rrn;
}
void Person::setMoney(int _money) {
    this->money = _money;
}
void Person::setName(std::string _name) {
    this->name = _name;
}
int Person::getRrn() {
    return this->rrn;
}
int Person::getMoney() {
    return this->money;
}
std::string Person::getName() {
    return this->name;
}

 void Student::pModify(int r, int m, std::string n) {
     this->pinm = r;
     this->money = m;
     this->name = n;
 }
void Student::setPinm(int p) {
    this->pinm = p;
}
int Student::getPinm() {
    return this->pinm;
}
void Student::setGrades(int g) {
    this->grades = g;
}
int Student::getGrades() {
    return this->grades;
}

       