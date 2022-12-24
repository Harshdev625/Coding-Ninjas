#include <iostream>
#include <cstring>
using namespace std;
void printSubstrings(char str[])
{
    int a = strlen(str) - 1;
    for (int i = 0; i <= a; i++)
    {
        int k = i;
        for (int j = i; j <= a; j++)
        {
            while (k <= j)
            {
                cout << str[k];
                k++;
            }
            k = i;
            cout << endl;
        }
    }
}
int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}