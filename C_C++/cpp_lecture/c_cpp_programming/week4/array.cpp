#include <iostream>

void NotArray() {
    int score1 = 50;
    int score2 = 30;
    int score3 = 90;
    int score4 = 0;
    // ...
    int score30 = 20;
}

void Array() {
    // Array defind
    int score[30] = {50, 30, 90, 0, 40, 27, 28};
}
void ArrayDataTypes();

int main() {

    ArrayDataTypes();
    return 0;
}

void ArrayDataTypes() {
    int arrayInt[3];

    for (int i = 0; i < sizeof(arrayInt); i++) {
        arrayInt[i] = i + 20;
    }

    std::cout << "arrayInt: " << arrayInt[0] << ", " << arrayInt[1] << ", " << arrayInt[2] << std::endl;

    double arrayDou[3];
    arrayDou[0] = 2.0;
    arrayDou[1] = 3.0;
    arrayDou[2] = 4.3;

    std::cout << "arrayDou: ";
    for (double d: arrayDou) {
        std::cout << d << ", ";
    }
    std::cout << std::endl;

    char arrayChar[3] = {'a', 'b', 'c'};
    std::cout << "arrayChar : ";
    for (int i = 0; i < sizeof(arrayChar); i++) {
        std::cout << arrayChar[i] << ", ";
    }
    std::cout << std::endl;
}