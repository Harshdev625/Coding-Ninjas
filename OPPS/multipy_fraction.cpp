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
    void multiply(fraction const &f2)
    {
        this->n = this->n * f2.n;
        this->d = this->d * f2.d;
        display();
    }
};
int main()
{
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    fraction f1(w, x);
    fraction f2(y, z);
    f1.multiply(f2);
}