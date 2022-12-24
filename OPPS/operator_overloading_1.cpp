#include <iostream>
using namespace std;
class fraction
{
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->denominator = denominator;
        this->numerator = numerator;
    }
    fraction add(fraction const &f2)
    {
        int lcm = (this->denominator) * f2.denominator;
        int x = (lcm / this->denominator);
        int y = (lcm / f2.denominator);
        int num = y * (f2.numerator) + x * this->numerator;
        fraction f3(num, lcm);
        f3.simplify();
        return f3;
    }
    fraction operator+(fraction const &f2) const
    {
        int lcm = (this->denominator) * f2.denominator;
        int x = (lcm / this->denominator);
        int y = (lcm / f2.denominator);
        int num = y * (f2.numerator) + x * this->numerator;
        fraction f3(num, lcm);
        f3.simplify();
        return f3;
    }
    fraction multiply(fraction const &f2)
    {
        int l = (this->denominator) * f2.denominator;
        int n = (f2.numerator) * this->numerator;
        fraction f3(n, l);
        f3.simplify();
        return f3;
    }
    fraction operator*(fraction const &f2) const
    {
        int l = (this->denominator) * f2.denominator;
        int n = (f2.numerator) * this->numerator;
        fraction f3(n, l);
        f3.simplify();
        return f3;
    }
    void simplify()
    {
        int gcd = 1;
        int a = min(this->numerator, this->denominator);
        for (int i = 1; i <= a; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    void operator==(fraction const &f2) const
    {
        bool b1 = (this->denominator == f2.denominator && f2.numerator == this->numerator);
        if (b1)
        {
            cout << "EQUAL" << endl;
        }
        else
            cout << "NOT EQUAL" << endl;
    }
    void display()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }
};
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    fraction f1(a, b);
    fraction f2(c, d);
    fraction f3 = f1.add(f2);
    fraction f4 = f1 + f2;
    fraction f5(3, 4);
    fraction f6 = f1 + f2 + f5;
    fraction f7 = f1.multiply(f2);
    fraction f8 = f1 * f2 * f5;
    f1.display();
    f2.display();
    f3.display();
    f4.display();
    f6.display();
    f7.display();
    f8.display();
    (f3 == f4);
    (f1 == f2);
}