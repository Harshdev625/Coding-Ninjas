#include <iostream>
using namespace std;
class fraction
{
private:
    int n;
    int d;

public:
    fraction(int n, int d)
    {
        this->n = n;
        this->d = d;
    }
    void hcf()
    {
        int c = 1;
        int d = min(this->d, this->n);
        for (int i = 2; i <= d; i++)
        {
            if (this->n % i == 0 && this->d % i == 0)
            {
                c = i;
            }
        }
        this->n = this->n / c;
        this->d = this->d / c;
    }
    void display()
    {
        hcf();
        cout << this->n << "/" << this->d << endl;
    }
    void add(fraction f2)
    {
        int lcm = this->d * f2.d;
        int a = lcm / this->d;
        int b = lcm / f2.d;
        this->n = this->n * a;
        f2.n = f2.n * b;
        this->n = this->n + f2.n;
        this->d = lcm;

        display();
    }
};
int main()
{
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    fraction f1(w, x);
    fraction f2(y, z);
    f1.add(f2);
}