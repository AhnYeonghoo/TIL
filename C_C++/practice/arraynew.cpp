#include <iostream>

int main() {

    using namespace std;
    double *p3 = new double[3]; // double형 데이터 3개를 저장할 수 있는 공간을 대입한다. p3을 배열의 이름처럼 취급한다.

    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1]은" << p3[1] << "입니다.\n";
    p3 = p3 + 1;
    cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
    cout << "p3[1]이 " << p3[1] << "입니다. \n";
    p3 = p3 - 1;
    delete[] p3;
    return 0;
}