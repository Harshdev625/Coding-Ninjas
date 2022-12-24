#include <iostream>
#include <cstring>
using namespace std;
class student
{
public:
    int age;
    char *name;
    const int x;
    int &y;
    student(int r) : x(r), y(this->age)
    {
    }
    void display()
    {
        cout << age << " " << name << " " << x << " " << y << endl;
    }
};
int main()
{
    int r;
    cin >> r;
    student s1(r);
    char a[100];
    cin >> a;
    s1.age = 67;
    s1.name = a;

    s1.display();
}