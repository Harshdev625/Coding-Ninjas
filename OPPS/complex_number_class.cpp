#include <iostream>
using namespace std;
class complex
{
private:
    int rp;
    int ip;

public:
    complex(int n, int d)
    {
        this->rp = n;
        this->ip = d;
    }
    void display()
    {
        cout << this->rp << "+i" << this->ip << endl;
    }
    void add(const complex &f2)
    {
        this->rp = this->rp + f2.rp;
        this->ip = this->ip + f2.ip;
    }
    void multiply(const complex &f2)
    {
        int a = this->rp * f2.rp - this->ip * f2.ip;
        int b = (this->rp * f2.ip) + (f2.rp * this->ip);
        this->rp = a;
        this->ip = b;
    }
};
int main()
{
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    complex f1(w, x);
    complex f2(y, z);
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        f1.add(f2);
        f1.display();
        f2.display();
    }
    else
    {
        f1.multiply(f2);
        f1.display();
        f2.display();
    }
}