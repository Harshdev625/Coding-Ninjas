#include <iostream>
using namespace std;
int staircase(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }
    int smalloutput1 = staircase(n - 1);
    int smalloutput2 = staircase(n - 2);
    int smalloutput3 = staircase(n - 3);
    return smalloutput3 + smalloutput2 + smalloutput1;
}
int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
}
