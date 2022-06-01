#include <iostream>

namespace A_RANGE {
    int score = 100;
    int fung(int s) {
        return s / 5;
    }
}

namespace B_RANGE {
    int score = 200;
    int fung(int s) {
        return s / 2;
    }
}

using namespace std;
using namespace A_RANGE;

int main() {
    cout << "score: " << score << endl;
    cout << "A_RANGE score: " << A_RANGE::score << endl;
    cout << "B_RANGE score: " << B_RANGE::score << endl;
}