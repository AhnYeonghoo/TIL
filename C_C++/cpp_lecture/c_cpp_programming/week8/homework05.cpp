#include <iostream>
#include <cmath>

#define PI 3.14

struct Point {
    double x, y;
};

class Circle {
    
    private:
        Point p;
        double radius, area;
        
        public:
        Circle(Point _p = {0, 0}, double _radius = 0.0):p(_p), radius(_radius), area(0){}

        double Area();
        Point getPoint() { return this->p; }
        double getRadius() { return this->radius; }
        double getArea() { return this->area; }
        void setX(double _x) { this->p.x = _x; }
        void setY(double _y) {this->p.y = _y; }
        void setPoint(Point _p) { this->p = _p; }
        void setRadius(double _r);
        ~Circle(){}
};

void Circle::setRadius(double _r) {
    this->radius = _r;
    this->area = Area();
}

double Circle::Area() {
    double area = pow(this->radius, 2) * PI;
    return area;
}



int main() {
    int n;
    do {
        std::cout << "Input Circle Number(Min: 5) : ";
        std::cin >> n;
        if (n < 5)
            std::cout << "It is less than the minimum number";
    } while (n < 5);

    Circle c[n];

    for (int i = 0; i < n; i++) {
        double _x, _y, _radius;
        std::cout << "Input Point and Radius" << std::endl;
        std::cin >> _x >> _y >> _radius;
        c[i].setPoint({_x, _y});
        c[i].setRadius(_radius);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (c[i].getArea() > c[j].getArea()) {
                Circle temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << "x : " << c[i].getPoint().x << ", y: " << c[i].getPoint().y << ", area: " << c[i].getArea() << std::endl;

    }
    return 0;
}