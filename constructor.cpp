#include <iostream>

class Date
{
private:
    int year_;
    int month_;
    int day_;

public:
    Date(int year, int month, int day)
    {
        year_ = year;
        month_ = month;
        day_ = day;
        ShowDate();
    }
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    int GetCurrentMonthTotalDays(int year, int month);

    void ShowDate();
};

void Date::SetDate(int year, int month, int day)
{
    // set함수로 클래스에 저장할 정보들을 입력받는다
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2)
    {
        // 2월이 아닌 경우
        return month_day[month - 1];
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        // 윤년인 경우
        return 29;
    }
    else
    {
        // 2월이지만 윤년이 아닌 경우
        return 28;
    }
}

void Date::AddDay(int inc)
{
    while (true)
    {
        int currentMonthTotalDays = GetCurrentMonthTotalDays(year_, month_);
        // 현재 월의 최대 일수

        if (day_ + inc <= currentMonthTotalDays)
        { // 더해진 값이 최대 일수보다 작으면 그대로 실행
            day_ += inc;
            return;
        }
        else
        { // 최대 일수보다 커질 경우 다음 월로 바꾸고 더할 날짜 수를 감소시켜 반복문을 통과시킨다.
            // 최종적으로 위 조건문이 실행될 때까지 반복한다.
            inc -= currentMonthTotalDays - day_ + 1;
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc)
{
    AddYear((inc + month_ - 1) / 12);
    // 더해진 월수가 최대 월수를 초과할 경우 12로 나운 몫을 년도에 더한다.
    month_ = month_ + inc % 12;
    // 더한 나머지는 현재 월수로 할당한다.
    month_ = (month_ == 12 ? 12 : month_ % 12);
    // 현재 월이 12가 아니라면 더해진 결과를 12로 나눈 나머지를 현재 월로 할당한다.
}

void Date::AddYear(int inc) { year_ += inc; }
// 년도의 제한조건이나 상위 데이터가 없으므로 증가치를 그대로 더한다.

void Date::ShowDate()
{
    std::cout << "today:" << year_ << '.' << month_ << '.' << day_ << std::endl;
}

int main()
{
    Date day(2024, 3, 21);
    day.ShowDate();
    // today:2024.3.21

    day.AddDay(30);
    day.ShowDate();
    // 2024.4.20

    Date secondDay(2030, 2, 11);
    secondDay.ShowDate();
    // 2030.2.11

    return 0;
}