//
// Created by Ahn_YeongHoo on 2022-05-27.
//

#include <iostream>
#include <cstring>
char* getname(void);
int main() {

    char * name;

    name = getname();
    std::cout << (int*) name << ": " << name << "\n";
    delete[] name;

    name = getname();
    std::cout << (int*) name << ": " << name << "\n";
    delete[] name;
    return 0;
}

char* getname() {
    char temp[80];
    std::cout << "이름을 입력하시오: ";
    std::cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    return pn;
}