#include <iostream>
#include <cmath>

double getLine(int ax, int ay, int bx, int by) {
    double line;
    line = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
    return line;
}

double getArea(double lineA, double lineB, double lineC) {
    double area, s;
    s = (lineA + lineB + lineC) / 2;
    area = sqrt(s * (s - lineA) * (s - lineB) * (s - lineC));
    return area;
}

bool getConfirm(double lineA, double lineB, double lineC) {
    return (lineA < lineB + lineC) && (lineB < lineA + lineC) && (lineC < lineA + lineB);
}

int main() {
    int x1, x2, x3;
    int y1, y2, y3;
    double lineA, lineB, lineC;
    double area;

    while (true) {
        std::cout << "input x1, y1: ";
        std::cin >> x1 >> y1;
        if (std::cin.eof()) {
            break;
        }
        std::cout << "input x2 y2: ";
        std::cin >> x2 >> y2;
        if (std::cin.eof()) {
            break;
        }
        std::cout << "input x3 y3: ";
        std::cin >> x3 >> y3;
        if (std::cin.eof()) {
            break;
        }

        lineA = getLine(x1, y1, x2, y2);
        lineB = getLine(x2, y2, x3, y3);
        lineC = getLine(x3, y3, x1, y1);
        
        if (getConfirm(lineA, lineB, lineC)) {
            area = getArea(lineA, lineB, lineC);
            std::cout << "This is Traingle" << std::endl;
            std::cout << "The area of a Triangle is " << area << std::endl;
        } else {
            std::cout << "This is not Triangle, Please Re-Enter" << std::endl;
        }
    
}
}