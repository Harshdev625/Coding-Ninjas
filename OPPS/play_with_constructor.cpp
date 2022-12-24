#include <iostream>
using namespace std;
class student
{
public:
    int age;

private:
    int roll;

public:
    student()
    {
        cout << "1" << endl;
    }
    student(int a)
    {
        cout << "2" << endl;
        age = a;
    }
    student(int a, int roll)
    {
        cout << "3" << endl;
        age = a;
        this->roll = roll;
    }
    void display()
    {
        cout << age << " " << roll << endl;
    }
    ~student()
    {
        cout << "destructor called" << endl;
    }
};
int main()
{
    student *s1 = new student(100, 101);
    student s2 = *s1; // copy constructor not copy assignment operator
    s1->display();
    s2.display();
}