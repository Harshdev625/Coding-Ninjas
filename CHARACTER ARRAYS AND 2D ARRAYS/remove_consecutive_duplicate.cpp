#include <iostream>
#include <cstring>
using namespace std;
void removeConsecutiveDuplicates(char input[])
{
    char a = input[0];
    int b = strlen(input);
    for (int i = 1; i < b && input[i] != '\0';)
    {
        if (input[i] == a)
        {
            int j;
            for (j = i; j < b - 1; j++)
            {
                input[j] = input[j + 1];
            }
            input[j] = '\0';
        }
        else
        {
            a = input[i];
            i++;
        }
    }
}
int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}