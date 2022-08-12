#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    int count;
    cin >> x;
    cin >> count;
    int price[count];
    int n[count];
    int sum = 0;
    for (int i = 0; i < count; i++) {
        cin >> price[i] >> n[i];
    }
    for (int i = 0; i < count; i++) {
        sum += price[i] * n[i];
    }
    if (sum == x) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}