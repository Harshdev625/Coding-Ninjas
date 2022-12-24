#include <iostream>
#include <cstring>
using namespace std;
class student
{
private:
    int age;

public:
    char *name;

public:
    student(int age, char *name)
    {
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
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
    student s2(s1);
    s2.display();
    s1.display();
    s2.name[3] = 'z';
    s2.display();
    s1.display();
}