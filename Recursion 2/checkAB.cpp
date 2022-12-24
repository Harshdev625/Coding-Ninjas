#include <iostream>
using namespace std;
bool checkAB1(char input[], int start)
{
    if (input[start] == '\0')
    {
        return true;
    }
    if (input[start] != 'a')
    {
        return false;
    }
    if (input[start + 1] != '\0' && input[start + 2] != '\0')
    {
        if (input[start + 1] == 'b' && input[start + 2] == 'b')
        {
            return checkAB1(input, start + 3);
        }
    }
    return checkAB1(input, start + 1);
}
bool checkAB(char input[])
{
    return checkAB1(input, 0);
}
int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
