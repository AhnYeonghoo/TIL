#include "figure.h"

class Rectangle : public Figure {
    private:
        Position position[2];

    public:
        Rectangle(double x1, double x2, double y1, double y2) {
            this->position[0].x = x1;
            this->position[1].x = x2;
            this->position[0].y = y1;
            this->position[1].y = y2;
        }
        Rectangle(){};

        double getWidth();
        double getHeight();
        double getArea();
        ~Rectangle() {
            std::cout << "Rectangle 소멸자" << std::endl;
        }
};