#include <iostream>
#include <cstring>
using namespace std;
char highestOccurringChar(char str[])
{
    int a[26] = {0};
    int b = strlen(str);
    for (int i = 0; i < b; i++)
    {
        int t = str[i] - 'a';
        a[t]++;
    }
    char x;
    int y = -1;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] > y)
        {
            x = ('a' + i);
            y = a[i];
        }
    }
    return x;
}
int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}