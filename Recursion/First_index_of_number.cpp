#include <iostream>
using namespace std;

int firstIndex(int input[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }

    if (input[0] == x)
    {
        return 0;
    }
    return firstIndex(input + 1, n - 1, x)+1;
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    cout << firstIndex(input, n, x) << endl;
}