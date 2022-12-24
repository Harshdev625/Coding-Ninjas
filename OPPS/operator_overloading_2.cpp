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

    fraction &operator++()
    {
        this->numerator = this->numerator + this->denominator;
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
    ++(++f1);
    ++(++f2);
    f1.display();
    f2.display();
}