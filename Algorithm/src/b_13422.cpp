#include <iostream>
#include <queue>
using namespace std;

// global Variable
int t;
int money[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int j = 0; j < n; j++) {
            cin >> money[j];
        }
        int count = 0;
        int rob_sum = 0;
        queue<int> q;
        for (int k = 0; k < m; k++) {
            q.push(money[k]);
            rob_sum += money[k];
        }
        if (rob_sum < k) {
            count++;
        }
        if (n != m) {
            for (int i = 1; i < n; i++) {
                int prev = q.front();
                int now = money[(i + m - 1) % n];
                rob_sum += (now - prev);
                q.pop();
                q.push(now);

                if (rob_sum < k)
                    count += 1;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
