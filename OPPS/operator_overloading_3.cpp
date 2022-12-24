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

    fraction operator++(int)
    {
        fraction f3(numerator, denominator);
        this->numerator = this->numerator + this->denominator;
        simplify();
        f3.simplify();
        return f3;
    }
    fraction &operator+=(fraction const &f2)
    {
        int lcm = (this->denominator) * f2.denominator;
        int x = (lcm / this->denominator);
        int y = (lcm / f2.denominator);
        int num = y * (f2.numerator) + x * this->numerator;
        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
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
    fraction f3 = f1++;
    fraction f4 = f2++;
    f1.display();
    f2.display();
    f3.display();
    f4.display();
    fraction f5 = (f1 += f2) += f2;
    f5.display();
}