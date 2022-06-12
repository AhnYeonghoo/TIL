#include <iostream>

class Person {

    private:
        std::string name;
    
    protected:
        std::string local;
        
    public:
        int age;
};

class Student : public Person {

    public:
        void print() {
            std::cout << local << std::endl;
            std::cout << age << std::endl;
        }
};

int main() {
    Person p;
    p.age;

    Student s;
    s.age;
}