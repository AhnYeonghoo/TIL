#include <iostream>

class Circle {
    public:
        Circle();
        Circle(int r);
        int radius;
        double getArea();
};

class Rectangle {
    public:
        int width;
        int height;
        int getArea();
};

class Point {
    int x, y;
    public:
        Point();
        Point(int a, int b);
        void show() { std::cout << "(" << x << ", " << y << ")" << std::endl;  }
};

Point::Point() : Point(0, 0) {}
Point::Point(int a, int b) 
    : x(a), y(b) { }

int Rectangle::getArea() {
    return width * height;
}

Circle::Circle() : Circle(1) {}

Circle::Circle(int r) {
    radius = r;
    std::cout << radius << " create circle " << std::endl;
}
double Circle::getArea() {
    return 3.14 * radius * radius;
}


int main() {
    Circle donut;
    donut.radius = 1;
    double area = donut.getArea();
    std::cout << area << std::endl;

    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea();
    std::cout << area << std::endl;

    Rectangle rec;
    rec.width = 3;
    rec.height = 5;
    std::cout << rec.getArea() << std::endl;

    Circle pizza2(30);
    area = pizza2.getArea();
    std::cout << area << std::endl;

    Point origin;
    Point target(10, 20);
    origin.show();
    target.show();
}