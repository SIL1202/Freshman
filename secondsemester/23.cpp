#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DateTime
{
public:
  DateTime() : date(), time() {}
  DateTime(string D)
  {
    stringstream ss(D);
    string strDate, strTime;
    getline(ss, strDate, ' '); //這裡必需getline 來分割空格 不然hour的第一個字不會被讀到
    getline(ss, strTime, ' ');
    date = Date(strDate);
    time = Time(strTime);
  }
  string toString() const
  {
    stringstream ss3;
    ss3 << date.toString() << " " << time.toString();
    return ss3.str();
  }

private:
  Date date;
  Time time;
};
