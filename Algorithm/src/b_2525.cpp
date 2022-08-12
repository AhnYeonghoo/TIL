#include <iostream>
using namespace std;

int main() {
    int hour, minute, time;
    cin >> hour >> minute >> time;

    hour += time / 60;
    minute += time % 60;
    
    if (minute >= 60) {
        hour += 1;
        minute -= 60;
    }
    if (hour >= 24) {
        hour -= 24;
    }


    cout << hour << " " << minute;
    return 0;
}