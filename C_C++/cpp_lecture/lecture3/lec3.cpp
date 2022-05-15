#include <iostream>

int main() {

    /*
    기본적인 자료형은 c언어와 동일
    */

    /*
    올바른 변수명: 단 번에 알아볼 수 있는 이름
    한글은 사용은 가능하지만, 권장되지 않는다.
    */

    int number_of_people; // OK
    int num_of_ppl;       // BAD

    int arr[10];
    int *parr = arr;

    int i;
    int *pi = &i;
    arr[0] = 10;
    std::cout << arr[0] << std::endl;
    std::cout << *parr << std::endl;

    /*
    변수명명은 카멜표기법, 스네이크 표기법이 있는데 구글에서는 스네이크 표기법을 취하고 있다.
    반면 함수는 대문자를 사용하는 카멜표기법을 사용한다.
    */
   
   /*
   조건문, 반복문, 기본적인 문법들도 c언어와 동일
   */

    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    int sum = 0;
    for (int i = 1; i < 11; i ++) {
        sum += i;
    }
    std::cout << sum << std::endl;

    int j = 0;
    sum = 0;
    while (j < 11) {
        sum += j;
        j++;
    }
    std::cout << sum << std::endl;

    int lucky_number = 3;
    std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

    int user_input;
    
    while (1) {
        std::cout << "입력: ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "맞추셨습니다~~" << std::endl;
            break;
        } else {
            std::cout << "다시 생각 해보세요~" << std::endl;
        }
    }

    return 0;
}