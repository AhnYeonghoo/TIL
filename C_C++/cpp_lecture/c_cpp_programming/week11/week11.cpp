// Template 

#include <iostream>
#include <cmath>

class Point {

    private:
        int x, y;
        
    public:
        Point(int _x, int _y): x(_x), y(_y) {}

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

        operator double() const { // return Trans Data Type(int to double)
            return sqrt(x * x + y * y);
        }

        friend std::ostream& operator<<(std::ostream& out, const Point& p) { // Pointer out
            out << "( " << p.x << " , " << p.y << " ) ";
            return out;
        }
        
        void pPrint() {
            std::cout << "x: " << x << ", y: " << y << std::endl;
        }

        ~Point(){}
};

int main() {

    /*
    Polymorphism(다형성)이란 여러가지 형태를 가질 수 있는 능력을 의미.
    한 타입의 참조변수로 여러 타입의 객체를 참조할 수 있다.

    Overloading(오버로딩)이란 동일한 이름의 메서드 여러개를 가지면서 매개변수의 유형과 개수가 다르도록 하는 기술.
    구분 기준은 매개변수의 개수 또는 자료형이다.

    Overriding(오버라이딩)이란 상위클래스가 가지고 있는 메서드를 하위 클래스가 재정의해서 사용하는 함수이다.
    맴버 함수의 동작만을 재정의하는 것으로 함수의 원형은 기존 맴버 함수의 원형과 같아야 한다.
    하위클래스는 상속 받을 때 명시한 접근 제어 권한에 맞는 상위클래스의 모든 맴버를 상속받는다.

    Operator Overloading(연산자 오버로딩)이란 오버로딩의 개념을 연산자까지 확대하여 하나의 연산자를 여러 의미로 사용할 수 있게 하는 것이다.
    기존의 제공하고 있는 연산자를 재정의하여 사용자 정의 함수로 사용하는 것이다.
    연산자를 오버로딩하기 위해서는 특수한 연산자 함수를 사용한다.(eg: +, - etc..)
    
    연산자 오버로딩에 대한 규칙
        - **과 같은 새로운 연산자 정의 불가능
        - 오버로드 된 연산자는 비정적 클래스 맴버함수거나 전역 함수여야 한다.
        - 기본 제공 데이터 형식에 적용할 때 연산자의 의미를 다시 정의할 수 없다.
        - 단항 연산자 또는 이항 연산자로 오버로드 가능하며 각 사용을 별도로 오버로드 할 수 있다.
        - 맴버 함수로 오버로드 된 연산자의 첫번째 파라미터는 항상 연산자가 호출되는 객체의 클래스 형식.
        
    오버로딩 불가능한 연산자
        - .(맴버선택)
        - .*(맴버 포인터 선택)
        - ::(범위)
        - ?:(조건)
        - #(문자열 전처리기 변환)
        - ##(전처리기 연결)


    입출력 안산자 오버로딩은 맴버 함수로는 구현할 수 없고, 전역함수로만 구현 가능.
        - 맴버 함수로 구현하기 위해선 ostream 클래스의 맴버 함수로 구현해야 하는데 ostream class는 C++ Standard이기 때문에
         직접 ostream 클래스의 맴버 함수로 A 타입의 객체를 인수로 받는 << 연산자 오버로딩을 만들어 줄 수는 없음.

    
    형변환 문법
        - Implicit Cast(묵시적 형변환)
            - 컴파일 시 묵시적으로 왼쪽 변수의 type으로 자동 형변환

        - Explicit Cast(명시적 형변환)
            - 변환할 type을 명시해주어 타입을 형변환

        - Static Cast
            - 논리적으로 변경 가능한 경우에만 변경을 허용하는 cpp의 문법
            - static_cast<type>(대상)으로 사용
            - 사용 가능 범위
                - 실수->정수, 정수->실수
                - 상위클래스 포인터가 상위클래스 가리키는것 가능
                - 하위클래스 포인터가 하위클래스 가리키는것 가능
                - 상위클래스 포인터가 하위클래스 가리키는것 가능(Upcasting)
                - 하위클래스 포인터가 상위클래스 가리키는것 가능(downcasting)
                - 포인터 타입을 정수 타입으로 변환 등은 불가능
            
    */
    float a = 3.14;
    int b;
    b = a; // a는 자동으로 int형으로 변환됨

    float a2 = 3.14;
    int b2;
    b2 = (int)a2;
    std::cout << b2 << std::endl;
    std::cout << b << std::endl;

    // 실수를 정수로, 정수를 실수로
    float f = 10.111;
    int i = static_cast<int>(f);
    std::cout << "int i : " << i << std::endl;

    f = static_cast<float>(i);
    std::cout << "float : " << f << std::endl;

    // Const Cast
    const int *const_int_ptr = new int(10);
    int *int_ptr;

    std::cout << *const_int_ptr << std::endl;

    int_ptr = const_cast<int *>(const_int_ptr); // const_int_ptr의 const 지정자를 잠시 제거
    *int_ptr = 20; // const_int_ptr은 상수이지만 const를 잠시 제거하여 값 변경
    std::cout << *const_int_ptr << std::endl;
    delete const_int_ptr;

    Point p1(20, 20);
    Point p2(50, 70);

    Point p = {10, 20};
    double l = p;
    std::cout << l << std::endl;
    std::cout << p << std::endl;
    Point p3 = p1 + p2;

    p3.pPrint();

    return 0;
}