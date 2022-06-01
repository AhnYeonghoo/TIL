// C++ Outline

/*
C언어
    - 절차지향 프로그래밍 언어
    - 컴퓨터가 이해하기 쉽게 작성된 프로그래밍 언어
    - 실행 속도가 매우 빠르지만, 사람이 배우기에는 매우 어려움

C++
    - 기존 C언어에 여러가지 기능을 추가하여 만든 프로그래밍 언어
    - 객체지향 프로그래밍 언어와 일반화 프로그래밍 언어를 모두 지원하는 언어
    - 다양한 방식을 지원하는 만큼, 다양한 기능을 모두 배워야 하는 부담으로 작용
    - namespace, string, OOP, templete, STL, etc...

기존 C언어와 C++의 헤더파일 차이
- stdio.h -> iostream
- math.h -> cmath

namespace
    - using namespace std;
    - std 이름공간에 있는 모든 이름을 사용할 수 있게 해준다는 의미

입출력
    - cin >> 변수 >> 변수>> 변수;
    - cout << 변수 << 변수 << 변수 << "string" << endl;

Variable(변수)
    - 데이터를 저장하기 위해 프로그램에 의해 이름을 할당받은 메모리 공간을 지칭
    - 즉, 데이터를 저장할 수 있는 메모리 공간을 의미
Variable Declaration
- int i;
- int a, b;
- char c;
- float f;

Initialization(초기화)
    - 변수 선언과 "동시에" 초기값을 지정하는 것

Assignment(할당)
    - 변수가 정의된 이 후, 대입 연산자(=)를 통해 값을 할당하는 것.

int i; -> 초기화x
i = 5; -> Assignment
int j = 7 -> 초기화 O

*/

#include <iostream>
#include <stdio.h>

void doPrint();
int returnInt();
char returnChar();
float returnFloat();
int addInt(int i, int sum);

int main() {

    int i;
    int j = 7;
    char c = 'a';
    float f = 9.22;

    printf("C Style Input\n");
    printf("Initialize variable i with value: ");
    i = 10;
    printf("C tyle Print\n");
    printf("Variable i has the value: %d \n", i);
    printf("Variable j has the value: %d \n", j);
    printf("Variable c has the value: %c \n", c);
    printf("Variable f has the value: %f \n", f);

    std::cout << "CPP style Input" << std::endl;
    std::cout << "Initialize variable i with value: ";
    //std::cin >> i;
    std::cout << "CPP style print" << std::endl;
    std::cout << "Variable i has the value: " << i << std::endl;
    std::cout << "Variable j has the value: " << j << std::endl;
    std::cout << "Variable c has the value: " << c << std::endl;
    std::cout << "Variable f has the value: " << f << std::endl;


    int k = 5;
    
    if (k > 5) {
        std::cout << "5보다 큽니다." << std::endl;
    } else if (k < 5) {
        std::cout << "5보다 작습니다." << std::endl;
    } else {
        std::cout << "5와 같습니다." << std::endl;
    }

    int s = 1;

    switch (s) {
        case 1:
            std::cout << "1입니다." << std::endl;
            break;
        case 2:
            std::cout << "2입니다." << std::endl;
            break;
        default:
            break;
    }

    int a = 0;
    int number = 5;

    while (a < number) {
        std::cout << "while문이 현재 " << a + 1 << "번째 반복 실행중입니다." << std::endl;
        a++;
    }
    a = 0;
    number = 5;
    do {
        std::cout << "do/while문이 현재 " << a + 1 << " 번째 반복 실행 중입니다." << std::endl;
        a++;
    } while (a < number);

    std::cout << "C style for statements" << std::endl;
    int p;
    for (p = 0; p < 5; p++) {
        std::cout << "for문이 현재 " << p + 1 << " 번째 반복 실행중입니다." << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "CPP style for statements" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "for문이 현재 " << i + 1 << " 번째 반복 실행중입니다." << std::endl;
    }

    int arr[5] = {0, 1, 2, 3, 4};
    
    for (int element:arr) {
        std::cout << "for문이 현재 " << element + 1 << " 번째 반복 실행중입니다." << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "returnInt() : " << returnInt() << std::endl;
    std::cout << "returnChar(): " << returnChar() << std::endl;
    std::cout << "returnFloat(): " << returnFloat() << std::endl;
    doPrint();

    std::cout << std::endl;
    std::cout << std::endl;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = addInt(i, sum);
        std::cout << "sum: " << sum << std::endl;
    }
    
}

void doPrint() {
    std::cout << "In doPrint()" << std::endl;
}

int returnInt() {
    return 5;
}

char returnChar() {
    return 'a';
}

float returnFloat() {
    return 1.1;
}

int addInt(int i, int sum) {
    return sum + i;
}