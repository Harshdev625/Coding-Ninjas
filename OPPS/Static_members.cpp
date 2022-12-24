#include <iostream>
using namespace std;
class student
{
    int age;
    int roll;
    static int totalstudent;

public:
    student()
    {
        totalstudent++;
    }
    static int gettotalstudent()
    {
        return totalstudent;
    }
};
int student ::totalstudent = 0;
int main()
{
    student s1;
    student s2;
    student s3;
    student *s4 = new student;
    student s5;
    student *s6 = new student;
    cout << student ::gettotalstudent() << endl;
}