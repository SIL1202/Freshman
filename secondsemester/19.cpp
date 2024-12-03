#include <iostream>
using namespace std;
class Fraction
{
private:
  int numer;
  int denom;

public:
  Fraction(int n = 0, int m = 1) : numer(n)
  {
    if (m == 0)
      throw "divided by zero";
    denom = m;
  }
  int getNumerator() const
  {
    return numer;
  }
  int getDenominator() const
  {
    return denom;
  }

  int __GCD(int a, int b)
  {
    if (a == 0)
      return b;
    else if (b == 0)
      return a;
    return __GCD(b, a % b);
  }
  int __LCM(int a, int b)
  {
    return a * b / __GCD(a, b);
  }

  Fraction operator+(const Fraction &f)
  {
    int n, d, _gcd, _lcm;
    _gcd = __GCD(getDenominator(), f.getDenominator());
    _lcm = __LCM(getDenominator(), f.getDenominator());
    n = getNumerator() * (_lcm / getDenominator()) + f.getNumerator() * (_lcm / f.getDenominator());
    d = _lcm;
    int temp = __GCD(n, d);
    n /= temp;
    d /= temp;
    return Fraction(n, d);
  }
  Fraction operator-(const Fraction &f)
  {
    int n, d, _gcd, _lcm;
    _gcd = __GCD(getDenominator(), f.getDenominator());
    _lcm = __LCM(getDenominator(), f.getDenominator());
    n = getNumerator() * (_lcm / getDenominator()) - f.getNumerator() * (_lcm / f.getDenominator());
    d = _lcm;
    int temp = __GCD(n, d);
    n /= temp;
    d /= temp;
    return Fraction(n, d);
  }
  Fraction operator*(const Fraction &f)
  {
    int n, d;
    n = getNumerator() * f.getNumerator();
    d = getDenominator() * f.getDenominator();
    int temp = __GCD(n, d);
    n /= temp;
    d /= temp;
    return Fraction(n, d);
  }
  Fraction operator/(const Fraction &f)
  {
    int n, d;
    n = getNumerator() * f.getDenominator();
    d = getDenominator() * f.getNumerator();
    int temp = __GCD(n, d);
    n /= temp;
    d /= temp;
    return Fraction(n, d);
  }
  Fraction operator!()
  {
    int reverse_n, reverse_d, _gcd;
    _gcd = __GCD(numer, denom);
    reverse_n = denom / _gcd;
    reverse_d = numer / _gcd;
    return Fraction(reverse_n, reverse_d);
  }
  friend ostream &operator<<(ostream &out, Fraction &f)
  {
    if (f.denom < 0)
    {
      f.denom *= -1;
      f.numer *= -1;
    }
    if (f.denom != 1)
      out << "(" << f.numer << "/" << f.denom << ")";
    else
      out << "(" << f.numer << ")";
    return out;
  }

  void operator=(const Fraction &f)
  {
    numer = f.getNumerator();
    denom = f.getDenominator();
  }

  void display()
  {
    cout << *this << endl;
  }
};


