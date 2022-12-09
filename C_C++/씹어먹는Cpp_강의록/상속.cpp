#include <iostream>
#include <string>

class Employee {

    std::string name;
    int age;

    std::string position;
    int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank)
            : name(name), age(age), position(position), rank(rank) {}
        
        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        Employee() {} // default constructor
        
        void PrintInfo() {
            std::cout << name << " (" << position << " , " << age << ") => " <<
                CalculatePay() << "$" << std::endl;
        }
        
        int CalculatePay() {
            return 200 + rank * 50;
        }
};

class EmployeeList {
    int alloc_employee;
    int current_employee;

    Employee** employee_list;

    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            current_employee = 0;
        }
        
        void AddEmployee(Employee* employee) {
            employee_list[current_employee] = employee;
            current_employee++;
        }

        int CurrentEmployeeNum() { return current_employee; }
        
        void PrintEmployeeInfo() {
            int total_pay = 0;
            for (int i = 0; i < current_employee; i++) {
                employee_list[i]->PrintInfo();
                total_pay += employee_list[i]->CalculatePay();
            }
            std::cout << "total cost: " << total_pay << "$ " << std::endl;
        }
        
        ~EmployeeList() {
            for (int i = 0; i < current_employee; i++) {
                delete employee_list[i];
            }
            delete[] employee_list;
        }
};

class Manager {
    std::string name;
    int age;
    
    std::string position;
    int rank, year_of_service;
    
    public:
        Manager(std::string name, int age, std::string position, int rank, int year_of_service)
            : year_of_service(year_of_service),
              name(name),
              age(age),
              position(position),
              rank(rank) {}
            
        Manager(const Manager& manager) {
            name = manager.name;
            age = manager.age;
            position = manager.position;
            rank = manager.rank;
            year_of_service = manager.year_of_service;
        }

        Manager() {}
        
        int CalculatePay() { return 200 + rank * 50 + 5 * year_of_service; }
        
        void PrintInfo() {
            std::cout << name << " (" << position << " , " << age << ", " << 
                year_of_service << "년차) ==> "  << CalculatePay() << "만원" << std::endl;
        }
};

class Base {
    std::string s;

    public:
        Base() : s("기반") { 
            std::cout << "base class" << std::endl;
        }
        
        void what() {
            std::cout << s << std::endl;
        }
};

class Derived : public Base {
    std::string s;

    public:
        Derived() : Base(), s("파생") {
            std::cout << "Derived Class" << std::endl;
        }
        void what() {
            std::cout << s << std::endl;
        }
};


int main() {
    EmployeeList emp_list(10);
    emp_list.AddEmployee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.AddEmployee(new Employee("노홍철", 34, "평사원", 1));
    

    emp_list.AddEmployee(new Employee("노홍철", 34, "평사원", 7));
    emp_list.AddEmployee(new Employee("노홍철", 34, "평사원", 4));
    emp_list.AddEmployee(new Employee("노홍철", 34, "평사원", 5));
    emp_list.AddEmployee(new Employee("노홍철", 34, "평사원", 2));
    emp_list.AddEmployee(new Employee("노홍철", 34, "평사원", 2));
    emp_list.PrintEmployeeInfo();

    std::cout << "\n\n\n";

    std::cout << "base class create" << std::endl;
    Base p;

    std::cout << "Derived class create" << std::endl;
    Derived c;
    return 0;
}