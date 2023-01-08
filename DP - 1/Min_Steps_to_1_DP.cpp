#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
// Dynammic Programming Approach to find out Minimum steps to convert a number to 1.
int countStepsToOne(int n)
{
    int *arr = new int[n + 1];
    arr[0]=0;
    arr[1]=0;
    for (int i = 2; i <= n; i++)
    {
        int ans=arr[i-1]+1;
        if(i%2==0){
            ans=min(ans,arr[i/2]+1);
        }
        if(i%3==0){
            ans=min(ans,arr[i/3]+1);
        }
        arr[i]=ans;
    }
    return arr[n];
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    cout << countStepsToOne(n);
    return 0;
}
