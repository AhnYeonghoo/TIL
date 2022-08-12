#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Minus(const int x, const int y) {
    cout << x - y << endl;
}
int Plus(const int x, const int y) {
    cout << x + y << endl;
}
namespace silla {
    int year = 935;
    void CentralArea() {
        cout << "gyeongsangdo" << endl;
    }
}
namespace baekjae {
    int year = 660;
    void CentralArea() {
        cout << "chung" << endl;
    }
}
int x = 10;
int Func1() {
    int y = x + 10;
    return y;
}
int Func2() {
    int x = 100;
    return x;
}

using namespace silla;
using namespace baekjae;

int main() {

    //Chapter1
    int number = 0;
    // cin >> number;
    cout << number << endl;
    int one = 1, two = 2;
    int sum = one + two;
    cout << sum << endl;
    const int GREATE_VICTORY_SALSU = 612;
    const int GREATE_VICTORY_GWIJU = 1019;
    cout << GREATE_VICTORY_SALSU << endl;
    cout << GREATE_VICTORY_GWIJU << endl;
    cout << one + two << endl;
    cout << one * two << endl;
    cout << one - two << endl;
    cout << one / two << endl;
    cout << one % two << endl;
    char character = 'C';
    int integer = 100;
    double precision = 3.14159;
    bool is_true = true;
    string word = "Hello World";
    cout << character << endl;
    cout << integer << endl;
    cout << precision << endl;
    cout << is_true << endl;
    cout << word << endl;
    int x1 = 10;
    int y = 1;
    if (x1 > y)
        cout << "x" << endl;
    else
        cout << "y" << endl;
    int sum1 = 0;
    int sum2 = 0;
    int one1 = 1;
    int two2 = 2;
    for (int i = 0; i < 5; i++) {
        sum1 += one1;
        sum2 += two2;
    }
    cout << sum1 << ", " << sum2 << endl;
    const int kArraySize = 3;
    int founding[kArraySize];
    founding[0] = 918;
    founding[1] = 1392;
    founding[2] = 1948;
    cout << founding[0] << endl;
    cout << founding[1] << endl;
    cout << founding[2] << endl;
    Minus(10, 5);
    Plus(2, 6);
    /**
     this is comment
    */
    silla::CentralArea();
    baekjae::CentralArea();
    cout << silla::year << endl;
    cout << baekjae::year << endl;
    vector<int> exam;
    exam.push_back(10);
    exam.push_back(20);
    exam.push_back(30);

    for (int i = 0; i < exam.size(); i++) {
        cout << "vector: " << exam.at(i) << endl;
    }
    cout << Func1() << endl;
    cout << Func2() << endl;
    cout << x << endl;

    // Chapter 2
    
}