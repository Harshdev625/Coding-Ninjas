#include <iostream>
using namespace std;
template <typename A, typename B>
class Pair
{
    A x;
    B y;

public:
    void setX(A x)
    {
        this->x = x;
    }
    A getX()
    {
        return x;
    }
    void setY(B y)
    {
        this->y = y;
    }
    B getY()
    {
        return y;
    }
};
int main()
{
    Pair<Pair<char, double>, Pair<int, float>> s;
    Pair<char, double> s1;
    Pair<int, float> s2;
    s1.setX('c');
    s1.setY(100.34);
    s2.setX(99);
    s2.setY(10.1);
    s.setX(s1);
    s.setY(s2);
    cout << s.getX().getX() << " " << s.getX().getY() << " " << s.getY().getX() << " " << s.getY().getY() << endl;
}