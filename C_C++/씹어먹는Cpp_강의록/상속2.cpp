#include <iostream>
#include <string>

class Base {
  public:
    std::string  parent_string;
    
    Base() : parent_string("기반") { 
        std::cout << "기반 클래스" << std::endl;
    }
    void what(){
        std::cout << parent_string << std::endl;
    }
};

class Derived : private Base {
    std::string child_string;
    
    public:
        Derived() : child_string("파생"), Base() {
            std::cout << "파생 클래스" << std::endl;
        }

        void what() {
            std::cout << child_string << std::endl;
        }
};


class Employee {
    protected:
        std::string name;
        int age;
        std::string position;
        int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank)
            : name(name), age(age), position(position), rank(rank) {}
        
        Employee(const Employee& e) {
            name = e.name;
            age = e.age;
            position = e.position;
            rank = e.rank;
        }
        Employee() {}

        void PrintInfo() {
            std::cout << name << " (" << position << " , " << age << ") ==> " 
            << CalculatePay() << std::endl;
        }
        
        int CalculatePay() { return 200 + rank * 50; }
    
};

class Manager : public Employee {

    
    int year_of_service;
    
    public:
        Manager(std::string name, int age, std::string position, int rank, int year_of_service)
            : Employee(name, age, position, rank),
              year_of_service(year_of_service) {}
        
        Manager(const Manager& manager) {
            Employee(manager.name, manager.age, manager.position, manager.rank),
            year_of_service = manager.year_of_service;
        }
        
        Manager() : Employee() {}

        
        int CalculatePay() { return 200 + rank * 50 + 5 * year_of_service; }
        void PrintInfo() {
            std::cout << name << " (" << position << " , " << age << ", "
                << year_of_service << "년차) ==> " << CalculatePay() << "만원"
                << std::endl;
        }
        
};

class EmployeeList {
    int alloc_employee;
    int current_employee;
    int current_manager;
    
    Employee** employee_list;
    Manager** manager_list;

    public:
        EmployeeList(int allloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            manager_list = new Manager*[alloc_employee];
            
            current_employee = 0;
            current_manager = 0;
        }
        void AddEmployee(Employee* employee) {
            employee_list[current_employee] = employee;
            current_employee++;
        }
        void AddManager(Manager* manager) {
            manager_list[current_manager] = manager;
            current_manager++;
        }
        int CureentEmployeeNum() { return current_employee + current_manager; }

        void PrintEmployeeInfo() {
            int total_pay = 0;
            for (int i = 0; i < current_employee; i++) {
                employee_list[i]->PrintInfo();
                total_pay += employee_list[i]->CalculatePay();
            }
            for (int i = 0; i < current_manager; i++) {
                manager_list[i]->PrintInfo();
                total_pay += manager_list[i]->CalculatePay();
            }
            std::cout << "총 비용: " << total_pay << "만원" << std::endl;
        }
        ~EmployeeList() {
            for (int i = 0; i <current_employee; i++) {
                delete employee_list[i];
            }
            for (int i = 0; i < current_manager; i++) {
                delete manager_list[i];
            }
            delete[] employee_list;
            delete[] manager_list;
            
        }
};



int main() {
    return 0;
}