#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    double sum = 0;
    int n;
    cin >> n;

    double score[1001];
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    sort(score, score + n);
    for (int i = 0; i < n; i++) {
        sum = sum+(score[i] / score[n - 1]) * 100;
    }
    cout << sum / n;
    return 0;
}