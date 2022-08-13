#include <iostream>

double area(int r);
double area(int r) {
    return 3.14 * r * r;
}
 

int main() {
    int n = 3;
    char c = '#';
    std::cout << c << 5.5 << '-' << n << "Hello" << true << std::endl;
    std::cout << "n + 5 = " << n + 5 << '\n';
    std::cout << "area is " << area(n);
    system("cls");
    // int width;
    // std::cout << "input the width";
    // std::cin >> width;
    // std::cout << "input the height";
    // int height;
    // std::cin >> height;
    // int area = width * height;
    // std::cout << "area is " << area << "\n"
    double area, radius;
    const double PI = 3.141592;
    std::cin >> radius;
    std::cout << "circle area is : " << PI * radius * radius << std::endl;
    std::cout << "Enter the name";
    char name[11];
    std::cin >> name;
    std::cout << "name is " << name << ".\n";
    std::cout << "한글 되나요?" << std::endl;
    
}