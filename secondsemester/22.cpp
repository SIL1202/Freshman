#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Date
{
public:
  Date() : year(1900), month(01), day(01) {}
  Date(string D)
  {
    stringstream ss(D);
    char d;
    ss >> year >> d >> month >> d >> day;
  }
  string toString() const
  {
    stringstream ss;
    ss << year << "/" << (month < 10 ? "0" : "") << month << "/" << (day < 10 ? "0" : "") << day;
    return ss.str();
  }
  int operator-(const Date &other)
  {
    int d1 = CountDays(year, month, day);
    int d2 = CountDays(other.year, other.month, other.day);
    return d1 - d2 < 0 ? (-1) * (d1 - d2) : d1 - d2;
  }

private:
  int year, month, day;

  bool IsLeapYear(int year)
  {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }

  int DayInMonth(int year, int month)
  {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(year) && month == 2)
      return 29;
    else
      return days[month];
  }

  int CountDays(int year, int month, int days)
  {
    for (int i = 1900; i < year; i++)
    {
      days += IsLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; i++)
    {
      days += DayInMonth(year, i);
    }
    return days;
  }
};

