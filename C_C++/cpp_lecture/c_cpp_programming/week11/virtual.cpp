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
            std::cout << "Hello Person " << n << std::endl;
        }
        void move() {
            std::cout << "Go to the home" << std::endl;
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
            std::cout << "Hello Person Override" << n   << std::endl;
        }
        void move() {
            std::cout << "Go to the Elementary" << std::endl;
        }
};

class Middle : public Person {
    
    public:
        Middle() {
            std::cout << "Hello Middle" << std::endl;
        }
        ~Middle() {
            std::cout << "Bye Middle" << std::endl;
        }
        void talk() {
            std::cout << "Middle" << std::endl;
        }
};

int main() {

    Person *pe = (Person *)new Elementary();
    std::cout << "start" << std::endl;
    pe->talk("kimm");
    pe->move();
    std::cout << "end" << std::endl;
    delete pe;


    return 0;
}