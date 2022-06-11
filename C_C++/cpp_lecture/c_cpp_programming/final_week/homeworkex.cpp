#include <iostream>
#include <cmath>
#include <memory>

struct POINT {
    int x, y;
};

class Figure {

    protected:
        POINT *point = nullptr;
        double *distance = nullptr;
        double area = 0.0;
        char type;

    public:
        Figure(POINT* _point, char _t):point(_point), type(_t) {
            std::cout << "F" << std::endl;
        }
        virtual void distance(){};
        virtual void area(){};
        virtual double reArea() = 0.0;
        virtual double *reDistance() = 0;
        double operator+(Figure &t) {
            if (type == t.type)
                return this->area + t.area;
            else
                return -1;
        }
        double operator-(Figure &t) {
            if (type == t.type)
                return this->area - t.area;
            else
                return -1;
        }
        double operator*(Figure &t) {
            if (type == t.type)
                return this->area * t.area;
            else
                return -1;
        }
        double operator/(Figure &t) {
            if (type == t.type)
                return this->area / t.area;
            else
                return -1;
        }
        virtual ~Figure() {
            std::cout << "~F" << std::endl;
            delete this->point;
            delete[] this->distance;
        }
};

class Triangle : public Figure {

    public:
        Triangle(POINT a, POINT b, POINT c) : Figure(this->rePOINT(a, b, c), 't') {
            std::cout << "T" << std::endl;
        }
        void distance() override {
            this->distance = this->reDistance();
        }
        void area() override{
            this->area = this->reArea()};
        POINT* rePOINT(POINT a, POINT b, POINT c) {
            return new POINT[3]{a, b, c};
        }
        double* reDistance() override {
            double dis[3];
            for (int i = 0; i < 3; i++) {
                int j = i + 1;
                if (j == 3)
                    j = 0;
                dis[i] = _distance(this->point[i], this->point[j]);
            }
            return new double[3]{dis[0], dis[1], dis[2]};
        };
        double _distance(POINT a, POINT b) {
            return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
        }
        double reArea() override {
            double dis[3];
            double _s = 0.0;
            for (int i = 0; i < 3; i++) {
                dis[i] = this->distance[i];
                _s += dis[i];
            }
            _s /= 2;
            double s = _s;
            for (double& d: dis) {
                s *= (_s - d);
            }
            s = sqrt(s);
            return s;
        }
        ~Triangle() {
            std::cout << "~T" << std::endl;
        }
};

class Circle : public Figure {
    
    private:
        POINT b;
        
    public:
        Circle(POINT a, POINT b): Figure(this->rePOINT(a), 'c'), b(b) {
            std::cout << "C" << std::endl;
        }
        POINT* rePOINT(POINT a) {
            return new POINT[1]{a}
        }
        void distance() override {
            this->distance = this->reDistance();
            std::cout << this->distance[0] << std::endl;
        }
        void area() override {
            this->area = this->reArea();
            std::cout << this->area << std::endl;
        }
        double* reDistance() override {
            double dis = sqrt(pow(this->point[0].x - b.x, 2) + pow(this->point[0].y - b.y, 2));
            return new double[1]{dis};
        };
        double reArea() override {
            double p = this->distance[0];
            return 3.14 * p * p;
        }
        ~Circle() {
            std::cout << "~C" << std::endl;
        }
};

int main() {

    POINT p_a[3] = {{0, 0}, {0, 4}, {3, 0}};
    POINT p_b[3] = {{0, 0}, {2, 2}, {4, 0}};
    POINT p_c[2] = {{0, 0}, {3, 4}};
    POINT p_d[2] = {{1, 1}, {2, 2}};
    Figure *_a = new Triangle(p_a[0], p_a[1], p_a[2]);
    Figure *_b = new Triangle(p_b[0], p_b[1], p_b[2]);
    Figure *_c = new Circle(p_c[0], p_c[1]);
    Figure *_d = new Circle(p_d[0], p_d[1]);
    _a->distance();
    _b->area();
    _b->distance();
    _b->area();
    _c->distance();
    _c->area();
    _d->distance();
    _d->area();
    std::cout << *_a + *_b << std::endl;
    std::cout << *_c + *_b << std::endl;
    std::cout << *_c + *_d << std::endl;

    delete _a;
    delete _b;
    delete _c;
    delete _d;
    return 0;
}