#include <iostream>
#include <cmath>

#define PI 3.14

struct Point {
    double x, y;
    double radius;
};

double area(Point _p) {
    double area = pow(_p.radius, 2) * PI;
    return area;
}

double line(Point _p) {
    double line = sqrt(pow(_p.x, 2) + pow(_p.y, 2));
    return line;
}

int main() {

    int n;
    do {
        std::cout << "Input Circle Number(Min: 5) : ";
        std::cin >> n;
        if (n < 5)
            std::cout << "It is less than the minimum nuber." << std::endl;
    } while (n < 5);

    Point *p = new Point[n];

    for (int i = 0; i < n; i++) {
        double _x, _y, _radius;
        std::cout << "Input Point and Radius" << std::endl;
        std::cin >> _x >> _y >> _radius;
        p[i].x = _x;
        p[i].y = _y;
        p[i].radius = _radius;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (area(p[i]) > area(p[j])) {
                Point temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            } else if (area(p[i]) == area(p[j])) {
                if (line(p[i]) > line(p[j])) {
                    Point temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << "x : " << p[i].x << ", y: " << p[i].y << ", area: " << area(p[i]) << std::endl;
    }
    delete[] p;
}