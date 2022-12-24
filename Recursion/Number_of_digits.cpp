#include <iostream>
using namespace std;
int count(int n)
{
    if (n >= 1 && n <= 9)
    {
        return 1;
    }
    return 1 + count(n / 10);
}
int main()
{
    int n;
    cin >> n;

    cout << count(n) << endl;
}
