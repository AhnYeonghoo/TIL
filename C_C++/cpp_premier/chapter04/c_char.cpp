#include <iostream>
#include <cstring>

int main() {

    char animal[20] = "bear"; // animal에 bear가 들어있다.
    const char *bird = "wren"; // bird에 문자열의 주소가 들어있다.
    char *ps; // 초기화되지 않았다.
    std::cout << animal << " and " << std::endl;
    std::cout << bird << "\n";

    // std::cout << ps << "\n" => 쓰레기 값

    std::cout << "동물의 종류를 입력하시오: ";
    std::cin >> animal;
    ps = animal;

    std::cout << ps << "s!\n";
    std::cout << "strcpy() 사용 전: \n";
    std::cout << (int *)animal << ": " << animal << std::endl;
    std::cout << (int *)ps << ": " << ps << std::endl;

    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);
    std::cout << "strcpy() 사용 후: \n";
    std::cout << (int*) animal << ": " << animal << std::endl;
    std::cout << (int *)ps << ": " << ps << std::endl;
    delete[] ps;
    

    return 0;
}