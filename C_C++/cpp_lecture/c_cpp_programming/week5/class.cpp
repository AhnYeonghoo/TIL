#include <iostream>
#include <string>

class Student {
    private:
        std::string name = "";
        int phone_number = 0;
        double score = 0;
    public:
    Student(std::string _name, int _phone_number, double _score) {
        this->name = _name;
        this->phone_number = _phone_number;
        this->score = _score;
        std::cout << "Hello Student " << std::endl;
    }

    void speaking();
    void inputInformation();
    void printInformation();

    ~Student() {
        std::cout << "By Student!" << std::endl;
    }
};

int main() {

    Student s("park", 98765432, 1.1);

    s.speaking();
    s.printInformation();

    s.inputInformation();
    s.printInformation();
}

void Student::speaking() {
    std::cout << "Hello Now Student!!  " << std::endl;
}

void Student::inputInformation() {
    this->name = "kim";
    this->phone_number = 12345678;
    this->score = 2.5;
}

void Student::printInformation() {
    std::cout << this->name << std::endl;
    std::cout << this->phone_number << std::endl;
    std::cout << this->score << std::endl;
}