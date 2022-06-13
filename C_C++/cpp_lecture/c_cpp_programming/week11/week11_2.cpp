#include <iostream>

class Person {
    
    public:
        Person() {
            std::cout << "Hello Person" << std::endl;
        }
        void talk() {
            std::cout << "Person" << std::endl;
        }
            
        ~Person(){
            std::cout << "Bye Person" << std::endl;
        }
};

class Student : public Person {
    

        Student(){}
        
     
         ~Student(){}
};

class Elementary : public Person {

    public:
        Elementary() {
            std::cout << "Hello Elementary" << std::endl;
        }
        ~Elementary() {
            std::cout << "Bye Elementary" << std::endl;
        }
        void talk() {
            std::cout << "Elementary" << std::endl;
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

    std::cout << "\n\n\n";
    std::cout << "Upcasting Declare" << std::endl;
    Person *pe = (Person *)new Elementary();
    std::cout << "Downcasting Declare" << std::endl;
    Middle *mp = (Middle *) new Person();
    std::cout << "-----start-----" << std::endl;
    pe->talk();
    mp->talk();
    std::cout << "-----end-----" << std::endl;

    std::cout << "Upcasting delete" << std::endl;
    delete pe;
    std::cout << "Downcasting delete" << std::endl;
    delete mp;

    return 0;
}