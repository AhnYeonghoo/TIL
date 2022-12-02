#include <iostream>

class Date {
    int year_;
    int month_;
    int day_;
    
    public:
        void ShowDate();
        
        Date() {
            std::cout << "default constructor" << std::endl;
            year_ = 2012;
            month_ = 7;
            day_ = 12;
        }

        Date(int year, int month, int day) {
            std::cout << "arguments 3 constructor" << std::endl;
            year_ = year;
            month_ = month;
            day_ = day;
        }
};


void Date::ShowDate() {
    std::cout << year_ << ", " << month_ << ", " << day_ << std::endl;
}

int main() {

    Date day = Date();
    Date day2(2012, 10, 31);
    day.ShowDate();
    day2.ShowDate();

    return 0;
}