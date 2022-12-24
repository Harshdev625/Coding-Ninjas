#include <iostream>
#include <cstring>
using namespace std;
void trimSpaces(char input[])
{
    int l = strlen(input);
    int j = 0;
    for (int i = 0; i < l; i++)
    {
        if (input[i] != ' ')
        {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
}
int main()
{
    int size = 1000000;
    char input[size];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input;
}