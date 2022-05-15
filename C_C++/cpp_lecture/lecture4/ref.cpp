#include <iostream>

// 참조자의 도입


int change_val(int *p) {
    /*
    기존 c언어식 swap
    */
    *p = 3;

    return 0;
}

int change_new_val(int &p) {
    /*
    cpp에서 도입한 레퍼런스로 swap
    */
    p = 3;
    return 0;
}

/* 참조자를 반환하는 함수 */

int& function(int &a) {
    a = 5;
    return a;
}

/* 일반적인 값을 반환하는 함수 */
int function2() {
    int a = 3;
    return a;
}

int main() {

    /*
    기존 c언어에서의 값 변경 방법
    */
    int number = 5;

    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;

    /*
    cpp에서 새롭게 도입한 레퍼런스(참조자) 문법
    레퍼런스 규칙
    1. 레퍼런스는 정의할 때 반드시 변수를 초기화 하여야 한다.
    2. 한 번 정해진 변수는 변경 불가능하다. (포인터와 다른점)
    3. 레퍼런스는 메모리 상에 존재하지 않을 수 있다.
    */

    int a = 3;
    int &another_a = a;

    another_a = 5;
    std::cout << "a: " << a << std::endl;
    std::cout << "another_a: " << another_a << std::endl;

    int number2 = 5;
    std::cout << number2 << std::endl;
    change_new_val(number2);
    std::cout << number2 << std::endl;

    /*
    여러 레퍼런스 예제들
    */

    int x; 
    int &y = x; // y는 x를 참조하는 레퍼런스다.
    int &z = y; // z는 y 참조자를 참조하는 레퍼런스다. y는 x를 참조하므로 결국 z는 x다.

    x = 1;
    std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;

    y = 2;
    std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;

    z = 3;
    std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;

    /*
    상수에 대한 레퍼런스는 불가능하다.
    하지만 const를 붙인 레퍼런스는 리터럴을 선언하는 것이 가능하다.
    */

    // int &ref = 4 no
    const int &ref = 4; // ok
    int a2 = ref; // a = 4와 동치

    // 레퍼런스의 레퍼런스, 레퍼런스의 배열, 레퍼런스의 포인터는 존재할 수 없다.
    // 하지만 배열들의 레퍼런스는 가능하다.

    int arr[3] = {1, 2, 3};
    int(&ref2)[3] = arr;
    ref2[0] = 2;
    ref2[1] = 3;
    ref2[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;

    int arr2[3][2] = {1, 2, 3, 4, 5, 6};
    int(&ref3)[3][2] = arr2;

    std::cout << ref3[0][0] << ref3[0][1] << ref3[1][0] << ref3[1][1] << ref3[2][0] << ref3[2][1] << ref3[3][0] << ref3[3][1] << std::endl;

    int b = 2;
    int c = function(b);
    std::cout << c << std::endl;

    // int& f = function2() // 레퍼런스 변수 f로 local variable 값을 반환받는다.
    // 이렇게 되면 함수가 끝남과 동시에 function2 지역변수는 소멸되므로 레퍼런스 변수 f는 아무것도 가르키지 못하는데
    // 이런 현상을 댕글링 레퍼런스라고 하며, 이는 오류를 발생시킨다.
    const int &f = function2(); // 단, const가 붙은 레퍼런스 변수는 리터럴을 할당할 수 있는 것과 같이 일반함수 또한
    // 초기화 할 수 있다. 이때 가능한 이유는 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값(여기서는 지역변수)의 생명주기가 연장된다.
    // 연장되는 기간은 레퍼런스가 사라질 때 까지다.
    std::cout << f << std::endl;


    return 0;

}