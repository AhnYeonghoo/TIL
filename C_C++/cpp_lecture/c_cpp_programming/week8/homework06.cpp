#include <iostream>
#include <string>

// 상위클래스
class Person {
    private:
        std::string SSID;

    protected:
        std::string name, local;
        int age;

    public:
        Person(std::string _SSID = "", std::string _name ="", std::string _local = "", int _age = 0)
        : SSID(_SSID), name(_name), local(_local), age(_age) {}
        ~Person(){};
        std::string move() { return "Home"; }
        std::string talk() { return "Very Tired"; }
        std::string Transporation() { return "Working."; }
        std::string setSSID() { return this->SSID; }
        std::string setName() { return this->name; }
        std::string setLocal() { return this->local; }
        int setAge() { return this->age; }
}

// 하위클래스

class Element : public Person  {
    
    private:
        int record;
        std::string BF;
        
        public:
            Element(std::string _SSID = "", std::string _name = "", std::string _local = "", int _age = 0,
                    int _record = 0, std::string _BF = "") : Person(_SSID, _name, _local, _age), record(_record), BF(_BF){};
            ~Elements(){};
            std::string move() { return "Senjoo"; }
            std::string talk() { return "Very Very Tired"; }
            std::string Transporation() { return "Bike"; }
            int getRecord() { this->record; }
            std::string getBF() { this->BF; }
};