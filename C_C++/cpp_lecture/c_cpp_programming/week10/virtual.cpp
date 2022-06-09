#include <iostream>
#include <string>

class Person {

    public:
        Person() {
            std::cout << "Hello Person First" << std::endl;
        }
        virtual ~Person() {
            std::cout << "Bye Person" << std::endl;
        }
        virtual void talk(std::string n) {
            std::cout << "Hello Persom" << n << std::endl;
        }
        void move() {
            std::cout << "Go to the Home" << std::endl;
        }
};

class Elementary : public Person {
    public:
        Elementary() {
            std::cout << "Hello Elementary" << std::endl;
        }
        ~Elementary() {
            std::cout << "Bye Elementary" << std::endl;
        }
        void talk(std::string n) override {
            std::cout << "Hello Person Override" << n << std::endl;
        }
        
        void move() {
            std::cout << "Go to the Elementary " << std::endl;
        }
};

int main() {

    Person *pe = (Person*)new Elementary(); // 업캐스팅
    std::cout << "start" << std::endl;
    pe->talk("kim");
    pe->move();
    delete pe;

}