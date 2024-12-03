int __LCM(int, int);
int __GCD(int, int);
int __LCM(int a, int b)
{
  return a * b / __GCD(a, b);
}
int __GCD(int a, int b)
{
  if (a == 0)
    return b;
  else if (b == 0)
    return a;
  return __GCD(b, a % b);
}

Fraction operator+(const Fraction f1, const Fraction f2)
{
  int n, d, _gcd, _lcm;
  _gcd = __GCD(f1.getDenominator(), f2.getDenominator());
  _lcm = __LCM(f1.getDenominator(), f2.getDenominator());
  n = f1.getNumerator() * (_lcm / f1.getDenominator()) + f2.getNumerator() * (_lcm / f2.getDenominator());
  d = _lcm;
  int temp = __GCD(n, d);
  n /= temp;
  d /= temp;
  return Fraction(n, d);
}
Fraction operator-(const Fraction f1, const Fraction f2)
{
  int n, d, _gcd, _lcm;
  _gcd = __GCD(f1.getDenominator(), f2.getDenominator());
  _lcm = __LCM(f1.getDenominator(), f2.getDenominator());
  n = f1.getNumerator() * (_lcm / f1.getDenominator()) - f2.getNumerator() * (_lcm / f2.getDenominator());
  d = _lcm;
  int temp = __GCD(n, d);
  n /= temp;
  d /= temp;
  return Fraction(n, d);
}
bool operator==(const Fraction f1, const Fraction f2)
{
  int n1, n2, _gcd, _lcm;
  _gcd = __GCD(f1.getDenominator(), f2.getDenominator());
  _lcm = __LCM(f1.getDenominator(), f2.getDenominator());
  n1 = f1.getNumerator() * (_lcm / f1.getDenominator());
  n2 = f2.getNumerator() * (_lcm / f2.getDenominator());
  return n1 == n2;
}
