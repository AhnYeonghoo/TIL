#include <iostream>

class Date {
    int year_;
    int month_;
    int day_;
    
    public:
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);
        int GetCurrentMonthTotalDays(int year, int month);
        void ShowDate();
        Date() {
            std::cout << "Default Constructor " << std::endl;
            year_ = 2012;
            month_ = 7;
            day_ = 12;
        }
        Date(int year, int month, int day) {
            year_ = year;
            month_ = month;
            day_ = day;
        }
};

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년 " << month_ << "월 " << day_
    << " 일 입니다. " << std::endl;
} 

int main() {
    Date day = Date();
    Date day2(2021, 10, 31);
    day.ShowDate();
    day2.ShowDate();
    return 0;
}
