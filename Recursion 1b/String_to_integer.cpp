#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int stringToNumber(char input[])
{
    if (strlen(input) == 1)
    {
        int a = input[0] - '0';
        return a;
    }
    int ans = stringToNumber(input + 1);
    if (strlen(input) > 1)
    {

        int b = input[0] - '0';
        return ans + b * (pow(10, strlen(input) - 1));
    }
    return ans;
}
int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}