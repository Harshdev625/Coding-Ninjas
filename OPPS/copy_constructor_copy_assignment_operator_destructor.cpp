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
    ~student(){
        cout<<"destructor called"<<endl;
    }
};
int main()
{
    student *s4 = new student(100, 101);
    student s1(*s4);
    student *s2 = new student(*s4);
    student s3(*s4);
    s1.display();
    s3.display();
    s2->display();
    s4->display();
    student s5(102, 103);
    student *s8 = new student(s5);
    student s7(s5);
    student *s9 = new student(s5);
    student s6(s5);
    s6.display();
    s7.display();
    s8->display();
    s9->display();
    student s10;
    // copy assignment operator(=)
    s10=s5;
    s10.display();
    delete s2;
    delete s4;
    delete s8;
    delete s9;
}