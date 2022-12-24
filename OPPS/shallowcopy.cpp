#include <iostream>
#include <cstring>
using namespace std;
class student
{
private:
    int age;
    char *name;

public:
    student(int age, char *name)
    {
        this->age = age;
        this->name = name;
    }
    void display()
    {
        cout << age << " " << name << endl;
    }
};
int main()
{
    char a[100];
    cin >> a;
    student s1(24, a);
    s1.display();
    a[3] = 'z';
    student s2(25, a);
    s2.display();
    s1.display();
}