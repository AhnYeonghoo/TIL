#include <iostream>
#include "Calculator.h"
#include "Adder.h"
using namespace std;



void Calculator::run() {
    cout << "Input the Two Numbers";
    int a, b;
    cin >> a >> b;
    Adder adder(a, b);
    cout << adder.process();
}