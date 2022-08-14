#include <iostream>
using namespace std;

class Rectangle {
public:
    int width, height;
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int length);
    bool isSquare();
    ~Rectangle();
};

Rectangle::~Rectangle() {
    cout << "Destructor" << endl;
    }
Rectangle::Rectangle() {
    width = height = 1;
}
Rectangle::Rectangle(int w, int h) {
    width = w;
    height = h;
}
Rectangle::Rectangle(int length) {
    width = height = length;
}
bool Rectangle::isSquare() {
    if (width == height)
        return true;
    else return false;
}

int main() {
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);
    if (rect1.isSquare())
        cout << "Rect1 is Square" << endl;
    if (rect2.isSquare())
        cout << "Rect2 is Square" << endl;
    if (rect3.isSquare())
        cout << "Rect3 is Square" << endl;
}