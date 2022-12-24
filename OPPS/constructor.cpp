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
};
int main()
{
    student s1;
    student *s2 = new student;
    student s3(5);
    student *s4 = new student(100, 101);

    s1.display();
    s3.display();
    s2->display();
    s4->display();
}