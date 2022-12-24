#include <iostream>
#include <cstring>
using namespace std;
class student
{
public:
    int age;
    int rollnumber;
    string s;
};
int main()
{
    student s1;
    student *s2 = new student;
    s1.age = 20;
    s1.rollnumber = 1;
    s1.s="harsh";
    cout << s1.age << " " << s1.rollnumber << " "<<s1.s<<endl;
    (*s2).age = 21;
    (*s2).rollnumber = 2;
    cout << (*s2).age << " " << (*s2).rollnumber << " ";
    student *s3 = new student;
    s3->age = 22;
    s3->rollnumber = 3;
    cout << (*s3).age << " " << (*s3).rollnumber;
}