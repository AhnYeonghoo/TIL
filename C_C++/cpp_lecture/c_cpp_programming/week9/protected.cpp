#include <iostream>

class Person {

    private:
        std::string name;
    
    protected:
        std::string local;
        
    public:
        int age;
};

class Student : protected Person {

    public:
        void print() {
            std::cout << local << std::endl;
            std::cout << age << std::endl;
        }
};

int main() {
    Person p;
    

    Student s;
    
}