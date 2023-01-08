#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
// Memoization apporach to find out Minimum steps to convert a number to 1.
int helper(int n, int arr[])
{
    if (n <= 1)
    {
        return 0;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    int x = helper(n - 1, arr);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = helper(n / 2, arr);
    }
    if (n % 3 == 0)
    {
        z = helper(n / 3, arr);
    }
    arr[n] = min(x, min(y, z))+1;
    return arr[n];
}
int countMinStepsToOne(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return helper(n, arr);
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
    return 0;
}
