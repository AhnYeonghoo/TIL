#include <iostream>

int main() {

    using namespace std;
    double wages[3] = {10000.0, 2000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    double *pw = wages;
    short *ps = stacks;

    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "pw 포인터에 1을 더함\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps += 1;
    cout << "ps 포인터에 1을 더함:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "배열 표기로 두 원소에 접근\n";
    cout << "stack[0] = " << stacks[0] << ", stacks[1]" << stacks[1] << endl;
    cout << "포인터 표기로 두 원소에 접근\n";
    cout << "*stacks = " << *stacks << ", *(stacks+1) = " << *(stacks + 1) << endl;

    cout << sizeof(wages) << " = wages 배열의 크기 \n";
    cout << sizeof(pw) << " = pw 포인터의 크기\n";
    return 0;
}