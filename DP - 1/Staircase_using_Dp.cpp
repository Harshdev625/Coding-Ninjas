#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
// Approach 1 Brute Force
long staircase(int n){
    if(n<=1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }
    return staircase( n-1)+staircase(n-2)+staircase( n-3);
}
// Approach 2 Memoization
long helper(int n,int arr[]){
    if(arr[n]!=-1){
        return arr[n];
    }
    arr[n]=helper(n-1,arr)+helper(n-2,arr)+helper(n-3,arr);
    return arr[n];
}
long staircase1(int n){
    int *arr =new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    return helper(n,arr);
}
// Aproach 3 Dynammic Programming
long staircase2(int n)
{
    long* arr = new long[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<=n; i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}
int main() {
    // your code goes here
    int n;
	cin >> n;
    cout << staircase(n)<<endl;
    cout << staircase1(n)<<endl;
	cout << staircase2(n)<<endl;
    return 0;
}
