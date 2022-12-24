#include <iostream>
#include <cstring>
using namespace std;
// METHOD 1
void removeConsecutiveDuplicates(char *input)
{
    if (input[0] == 0 || input[1] == 1)
    {
        return;
    }
    else
    {
        if (input[0] == input[1])
        {
            int j;
            int b = strlen(input);
            for (j = 1; j <= b - 1; j++)
            {
                input[j - 1] = input[j];
            }
            input[j - 1] = '\0';
            return removeConsecutiveDuplicates(input);
        }
        else
        {
            return removeConsecutiveDuplicates(input + 1);
        }
    }
}
// METHOD 2
void removeConsecutiveDuplicates(char *input)
{
    if (strlen(input) == 0 || strlen(input) == 1)
    {
        return;
    }
    if (input[0] == input[1])
    {
        int j = 0;
        // int b=strlen(input);
        for (; /*j<b-1*/ input[j] != '\0'; j++)
        {
            input[j] = input[j + 1];
        }
        // input[j]='\0';
        removeConsecutiveDuplicates(input);
    }
    else
    {
        removeConsecutiveDuplicates(input + 1);
    }
}
int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}