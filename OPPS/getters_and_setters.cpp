#include <iostream>
using namespace std;
class student
{
public:
    int age;

private:
    int roll;

public:
    void display()
    {
        cout << age << " " << roll << endl;
    }
    void setage()
    {
        int a;
        cin >> a;
        roll = a;
    }
};
int main()
{
    student s1;
    student *s2 = new student;
    s1.display();
    s1.age = 1;
    s1.setage();
    s1.display();
    s2->display();
    (*s2).age = 2;
    s2->setage();
    s2->display();
}