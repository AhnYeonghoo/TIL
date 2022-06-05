
#include <iostream>
#include <string>

using namespace std;
typedef struct student {
    char name[6];
    int age;
    double score;
} STUDENT;


int main() {

    int *ptr1 = new int(10);
    int *ptr2 = new int;

    *ptr2 = 20;
    std::cout << "ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << std::endl;
    delete ptr1, ptr2;

    int *ptr3 = new int[10];
    ptr3[0] = 10;
    ptr3[1] = 20;
    ptr3[2] = 30;
    std::cout << ptr3[1] << std::endl;
    std::cout << *(ptr3 + 2) << std::endl;

    delete[] ptr3;

    STUDENT *p = new STUDENT;
    strcpy_s(p->name, "park");
    p->age = 22;
    p->score = 80.8;

    std::cout << p->name << std::endl;
    std::cout << p->age << std::endl;
    std::cout << p->score << std::endl;
    delete p;
    return 0;
    
}