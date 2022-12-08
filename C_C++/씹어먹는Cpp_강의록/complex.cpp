#include <iostream>
#include <string.h>

class Complex {

    private:
        double real, img;

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }

        Complex operator+(const Complex& c);
        Complex operator+(const char* str);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);
        Complex& operator=(const Complex& c);
        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        friend std::ostream& operator<<(std::ostream& os, const Complex& c);

        void println() { 
            std::cout << "( " << real << " , " << img << " ) " << std::endl;
        }

        double GetNumber(const char* str, int from, int to);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "( " << c.real << " , " << c.img << " ) " ;
    return os;
}

Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}

double Complex::GetNumber(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;
    
    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.') {
            integer_part = false;
        } else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] -'0') * decimal);
        } else {
            break;
        }

        if (minus) num *= -1.0;
        
        return num;
    }
}

Complex Complex::operator+(const char* str) {
    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;
    
    int pos_i = -1;
    for (int i = 0;  i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    if (pos_i == -1) {
        str_real = GetNumber(str, begin, end - 1);
        Complex temp(str_real, str_img);
        return (*this) + temp;
    }

    str_real = GetNumber(str, begin, pos_i - 1);
    str_img = GetNumber(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

    Complex temp(str_real, str_img);
    return (*this) + temp;

}

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    
    Complex c = a * b;
    c.println();
}


