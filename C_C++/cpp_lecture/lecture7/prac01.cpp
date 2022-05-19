#include <iostream>

class Date {
    private:
        int year;
        int month;
        int day;

    public:
        void set_date(int _year, int _month, int _date);
        void add_day(int inc);
        void add_month(int inc);
        void add_year(int inc);

        int get_current_month_total_days(int year, int month);

        void show_date();
};

void Date::set_date(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
}

int Date::get_current_month_total_days(int year, int month) {
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month != 2) {
        return month_day[month - 1];
    } else if (year % 4 == 0 && year % 100 == 0) {
        return 29;
    } else {
        return 28;
    }
}

void Date::add_day(int inc) {
    while (true) {

        int current_month_total_days = get_current_month_total_days(year, month);

        if (day + inc <= current_month_total_days) {
            day += inc;
            return;
        } else {
            inc -= (current_month_total_days - day + 1);
            day = 1;
            add_month(1);
        }
    }
}

void Date::add_month(int inc) {

    add_year((inc + month - 1) / 12);
    month = month + inc % 12;
    month = (month == 12 ? 12 : month % 12);
}

void Date::add_year(int inc) { year += inc; }
void Date::show_date() {
    std::cout << "오늘은 " << year << "년" <<  " " << month << "월 " << day << "일 입니다. " << std::endl;
}

int main() {

    Date day;
    day.set_date(2011, 3, 1);
    day.show_date();

    day.add_day(30);
    day.show_date();

    day.add_day(2000);
    day.show_date();

    day.set_date(2012, 1, 31);
    day.add_day(29);
    day.show_date();

    day.set_date(2012, 8, 4);
    day.add_day(2500);
    day.show_date();
    return 0;
}
