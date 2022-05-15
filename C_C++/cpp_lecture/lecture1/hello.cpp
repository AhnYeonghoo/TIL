#include <iostream>
#include "header1.h"
#include "header2.h"

// 이름없는 namespace는 마치 static 변수와 같이 해당 파일 안에서만 접근이 가능해진다.

namespace {
    int only_in_this_file() {}
    int only_in_this_file = 0;
}

int main() {
    
    /*
    std는 C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 namespace이다.
    */
    std::cout << "Hello World" << std::endl;

    /*
    이처럼 각 객체의 이름공간을 명시해주어야만 한다.
    */
    header1::foo();
    header1::var();
    header2::foo();
    header2::var();

    only_in_this_file = 3;
    only_in_this_file();

    return 0;
}