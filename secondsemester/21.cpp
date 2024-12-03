#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Time
{
public:
    Time() : hour(0), minute(0), second(0) {}
    Time(string T)
    {
        stringstream ss(T);
        char d = ':';
        ss >> hour >> d >> minute >> d >> second;
    }
    string toString() const
    {
        stringstream ss;
        ss << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute << ":" << (second < 10 ? "0" : "") << second;
        return ss.str();
    }
    int operator-(const Time &other) const
    {
        int t1_second = (hour * 3600) + (minute * 60) + second;
        int t2_second = (other.hour * 3600) + (other.minute * 60) + other.second;
        int x = t1_second - t2_second;
        return (x < 0 ? (-1) * x : x);
    }

private:
    int hour, minute, second;
};

