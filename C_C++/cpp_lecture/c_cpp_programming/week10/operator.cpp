#include <iostream>
#include <cmath>

class Point {

    private:
        int x, y;

        public:
            Point(int _x, int _y) : x(_y), y(_y){}
            Point sum(Point t) {
                Point temp(x + t.x, y + t.y);
                return temp;
            }
            Point operator + (Point t) {
                return Point(x + t.x, y + t.y);
            }

            Point operator - (Point t) {
                return Point(x - t.x, y - t.y);
            }

            operator double() const {
                return sqrt(x * x + y * y);
            }
            
            friend std::ostream& operator<<(std::ostream& out, const Point& p) {
                out << "( " << p.x << ", " << p.y << ") ";
                return out;
            }

            ~Point(){};
};

int main() {
    Point p1(10, 20);
    Point p2(50, 70);

    Point p3 = p1 - p2;
    std::cout << p3 << std::endl;
    return 0;
}