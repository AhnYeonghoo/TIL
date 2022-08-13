#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char password[11];
    cout << "프로그램을 종료하려면 암호를 입력하세요. " << endl;
    while (true) {
        cout << "password >>";
        cin >> password;
        if (strcmp(password, "C++") == 0) {
            cout << "Program doneㅇㅇㅇ" << endl;
            break;
        } else {
            cout << "password is wrongㄴㄴㄴ" << endl;
        }
    }
}