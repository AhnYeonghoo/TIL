#include <iostream>

class Date {
private:
    int year;
    int month;
    int day;

    public:
        void set_date(int _year, int _month, int _day);
        void add_day(int inc);
        void add_month(int inc);
        void add_year(int inc);

        int get_current_month_total_days(int _year, int _month);

        void show_date();
        
        //Contructor(생성자)
        Date(int _year, int _month, int _day) {
            year = _year;
            month = _month;
            day = _day;
        }

        // default Contructor (디폴트 생성자)
        Date() { 
            year = 2012;
            month = 7;
            day = 12;
        }

        Date() = default; // 디폴트 생성자 정의하지 않아도 자동으로 디폴트 생성자 호출
};

void Date::add_year(int inc) { year += inc; }
void Date::show_date() {
    std::cout << "오늘은 " << year << " 년" << month << " 월" << day << " 일 입니다." << std::endl;
}

int main() {

    Date day(2011, 3, 1);
    day.show_date();

    day.add_year(10);
    day.show_date();

    Date day2;
    day2.show_date();

    return 0;
}