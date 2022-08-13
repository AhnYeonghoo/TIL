#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Input the Address";

    char address[100];
    cin.getline(address, 100, '\n');
    cout << "address is " << address << endl;
    system("cls");
    string song = "Falling in love with you";
    string elvis("Elvis Presley");
    string singer;
    cout << song + " that singer ";
    cout << "(hint : first voca " << elvis[0] << ")?";

    getline(cin, singer);

    if (singer == elvis) {
        cout << "done" << endl;
    } else {
        cout << "nope" << elvis << endl;
    }

    char city[21];
    cin.getline(city, 20, '.');
    cout << city << endl;
}