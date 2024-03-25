#include <iostream>

class Date
{
    int year;
    int month;
    int day;

public:
    void showDate();

    Date()
    // 디폴트 생성자
    {
        year = 2024;
        month = 3;
        day = 25;
    }
    Date(int year_, int month_, int day_)
    // 입력을 받을 때의 생성자
    {
        year = year_;
        month = month_;
        day = day_;
    }
};

void Date::showDate()
{
    std::cout << "today is " << year << "." << month << "." << day << std::endl;
}

int main()
{
    Date day = Date(2024, 5, 29);
    Date day2;

    day.showDate();
    // today is 2024.3.25
    day2.showDate();
    // today is 2024.3.25

    return 0;
}