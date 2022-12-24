#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(char input[], int start, int end)
{
    if (start > end)
    {
        return true;
    }
    if (input[start] != input[end])
    {
        return false;
    }
    return isPalindrome(input, start + 1, end - 1);
}
bool checkPalindrome(char input[])
{
    int len = strlen(input);
    int start = 0, end = len - 1;
    return isPalindrome(input, start, end);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
