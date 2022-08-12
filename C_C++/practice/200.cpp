#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
class Temp {
    int no;
    int no2;
    bool is_on;
};
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
    char ch1 = 'c';
    char ch2 = 200;
    unsigned char ch3 = 'c';
    unsigned char ch4 = 200;
    printf("%d, %c", ch1, ch1);
    cout << endl;
    printf("%d, %c", ch2, ch2);
    cout << endl;
    printf("%d, %c", ch3, ch3);
    cout << endl;
    printf("%d, %c", ch4, ch4);
    cout << endl;
    string my_contry = "korea";
    string my_job = "developer";
    cout << my_contry << endl;
    cout << my_job << endl;
    string my_info = my_contry + ", " + my_job;
    cout << my_info << endl;
    system("cls");
    int positive = 100;
    int negative = -200;
    int ascii_value = 'A';
    cout << positive << endl;
    cout << negative << endl;
    cout << ascii_value << endl;
    double pi_d = 3.14;
    float pi_f = 3.14f;
    cout << pi_d << endl;
    cout << pi_f << endl;
    int x2 = 10;
    int y2 = 6;
    bool is_true1 = false;
    if (x2 > y2) {
        is_true1 = true;
    } else {
        is_true1 = false;
    } 
    if (is_true1 == true) {
        cout << "x is big" << endl;
    } else {
        cout << "y is big" << endl;
    }
    system("cls");
    x = 1;
    y = 9;
    int z = x + y;
    double i = 1.2;
    double j = 2.3;
    double k = i + j;
    cout << z << endl;
    cout << k << endl;
    x = 1;
    y = -1;
    z = -2;
    cout << x + y << endl;
    cout << y + z << endl;
    x = 1;
    cout << x++ << endl; // 1
    cout << x++ << endl; // 2
    cout << ++x << endl; // 4
    cout << x-- << endl; // 4
    cout << x-- << endl; // 3
    cout << --x << endl; // 1
    string publisher = "정보문화사";
    string language = "C++";
    x = 10;
    y = 10;
    if (publisher != language) {
        cout << "diff" << endl;
    } else {
        cout << "equal" << endl;
    }
    if (x >= y) {
        cout << "x>=y" << endl;
    } else {
        cout << "x>!=y" << endl;
    }
    if (x <= 20) {
        cout << "x <= 20" << endl;
    } else {
        cout << "x <!= 20" << endl;
    }
    x = 10;
    y = 20;
    bool is_x = true;
    bool is_y = false;
    
    if (is_x == true && is_y == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    if (x == 10 || is_x == false) {
        cout << "x==10 or is_x == false" << endl;
    } else {
        cout << "not" << endl;
    }
    if (!is_y) {
        cout << "!is_y == true" << endl;
    } else {
        cout << "!is_y == false" << endl;
    }
    x = 1, y = 2, z = 0;
    z = x > y ? x : y; // z = 2;
    cout << z << endl;
    int goguryeo = 37, baekjae2 = 18, silla2 = 57;
    printf("삼국 건국연도\n");
    printf("고구려 bc%d년, 백제 bc%d년, 신라 bc%d년\n", goguryeo, baekjae2, silla2);
    bitset<8> bit1;
    bit1.reset(); // 0000 0000
    bit1 = 127;

    bitset<8> bit2;
    bit2.reset();
    bit2 = 0x20; // 32

    bitset<8> bit3 = bit1 & bit2;
    bitset<8> bit4 = bit1 | bit2;
    bitset<8> bit5 = bit1 ^ bit2;
    bitset<8> bit6 = ~bit1;
    bitset<8> bit7 = bit2 << 1;
    bitset<8> bit8 = bit2 >> 1;
    bitset<8> bit9 = bit1 << 1;
    cout << bit3.to_ulong() << endl;
    cout << bit3.to_ulong() << endl;
    cout << bit4.to_ulong() << endl;
    cout << bit5.to_ulong() << endl;
    cout << bit6.to_ulong() << endl;
    cout << bit7.to_ulong() << endl;
    cout << bit8.to_ulong() << endl;
    cout << bit9.to_ulong() << endl;
    system("cls");
    x = 2;
    double dy = 4.4;
    int ii = static_cast<int>(dy / x);
    int jj = (int)(dy / x);
    double dk = dy / x;
    cout << ii << endl;
    cout << jj << endl;
    cout << dk << endl;
    cout << sizeof('p') << endl; // 1byte
    cout << sizeof(10) << endl; // 4byte
    cout << sizeof(10.0) << endl; // 8byte
    cout << sizeof(Temp) << endl; // 4byte
    system("cls");
}