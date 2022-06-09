#include <iostream>
#include <string>

class Person {

    private:
        std::string ssNumber;
        
    protected:
        int age;
        std::string name;

    public:
        Person(std::string _ssNumber = "", int _age=0, std::string _name = "")
            : ssNumber(_ssNumber), age(_age), name(_name){}
        ~Person() {}
        void talk();
        void move();
};

class Student : public Person {

    private:
        std::string academic;
        std::string id;

    public:
        Student(std::string _ssNumber ="", int _age=0, std::string _name="", std::string _academic = "", std::string _id = "")
            : Person(_ssNumber, _age, _name), academic(_academic), id(_id){}
        ~Student(){}
        void move();
        void study();
};

void Person::move() {
    std::cout << this->name << "is going home" << std::endl;
}

void Student::move() {
    std::cout << this->name << "is going" << this->academic << "University" << std::endl;
}

void Person::talk() {
    std::cout << "사람이 말한다. " << std::endl;
}

void Student::study() {
    std::cout << "he is studying " << std::endl;
}


int main() {

    Person p("00-00", 10, "Kim");
    p.move();
    p.talk();

    Student s("00-01", 22, "Lee", "CBNU", "2021040016");
    s.move();
    s.Person::move();
    s.talk();
    s.study();

}