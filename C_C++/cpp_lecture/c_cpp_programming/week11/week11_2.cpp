#include <iostream>

class Person {
    Person(int _age): age(_age){}
    Person(): age(0){}
    private:
        int age;

        public:
            int get_age() { return this.age; }
            
    virtual ~Person(){}
};

class Student : public Person {
    Student(int _study): study(_study) {}
    Student(): study(0){}

     private: 
        int study;
        
     public:
         int get_age() { return age + study; }

         ~Student(){}
};

int main() {
    int *int_ptr = new int(10);
    const int *c_int_ptr = new int(15);

    char *char_ptr;
    std::cout << "Before: " << std::endl;
    std::cout << "*int_ptr: " << *int_ptr << std::endl;
    std::cout << "*c_int_ptr: " << *c_int_ptr << std::endl;

    // 명시적 형 변환
    char_ptr = reinterpret_cast<char *>(int_ptr);
    *char_ptr = 20;

    std::cout << "명시적 형 변환" << std::endl;
    std::cout << "*int_ptr: " << *int_ptr << std::endl;
    
    // const 지정자 사용 시, 명시적 형 변환
    char_ptr = reinterpret_cast<char *>(const_cast<int *>(c_int_ptr));
    *char_ptr = 30;

    std::cout << "const 지정자 사용 시" << std::endl;
    std::cout << "*int_ptr: " << *int_ptr << std::endl;
    std::cout << "*c_int_ptr: " << *c_int_ptr << std::endl;


    /* 
    dynamic cast는 Class의 포인터 간 형 변환 시, 안전하게 down casting을 위해 사용
    단, 상위클래스에 virtual이 존재해야 정상 작동.


    */

    Person *ptr_p = new Student();
    Student *ptr_s;

    ptr_p->age = 200;
    ptr_p->get_age();
    ptr_s = dynamic_cast<Student *>(ptr_p);

    if (ptr_p == nullptr) {
        std::cout << "error compile" << std::endl;
    }

    ptr_s->study = 20;
    ptr_s->get_age();

    delete ptr_p;
    return 0;
}