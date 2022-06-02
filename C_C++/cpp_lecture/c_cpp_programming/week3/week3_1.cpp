#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main() {

    char c_string[] = "Hello CBNU C style";
    cout << "text: " << c_string << endl;
    cout << "type: " << typeid(c_string).name() << endl;
    cout << "long: " << sizeof(c_string) << endl;

    for (int i = 0; i < sizeof(c_string); i++) {
        if (c_string[i] == '\0') {
            cout << "have NULL" << endl;
            break;
        } else if (i == sizeof(c_string) - 1) {
            cout << "have not NULL" << endl;
        }
    }

    string s_string = "Hello CBNU CPP style";
    cout << "text: " << s_string << endl;
    cout << "type: " << typeid(s_string).name() << endl;
    cout << "long: " << s_string.size() << endl;
    for (int i = 0; i < s_string.size(); i++) {
        if (s_string[i] == '\0') {
            cout << "Have NULL" << endl;
            break;
        } else if (i == s_string.size() - 1) {
            cout << "have not NULL" << endl;
        }
    }
}