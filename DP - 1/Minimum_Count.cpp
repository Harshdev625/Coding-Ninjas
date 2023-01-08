#include <bits/stdc++.h>
using namespace std;
// Approach 1 Brute Force
int minCount(int n){
    if(n<=0){
        return 0;
    }
    int count =INT_MAX;
    for(int i=1;i*i<=n;i++){
        int t=minCount(n-(i*i));
        count=min(count,t);
    }
    return 1+count;
}
// Approach 2 Memoization
int helper(int n,int arr[]){
    if(arr[n]!=-1){
        return arr[n];
    }
    int count=INT_MAX;
    for(int i=1;i*i<=n;i++){
        int t=helper(n-(i*i),arr);
        count=min(count,t);
    }
    arr[n]=count+1;
    return arr[n];
}
int minCount1(int n){
    int *arr =new int[n+1];
    
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    arr[0]=0;
    return helper( n,arr);
}
// Approach 3 Dynamic Programming 
int minCount2(int n){
    int *arr =new int[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++){
        int count=INT_MAX;
        for(int j=1;j*j<=i;j++){
            count=min(count,arr[i-(j*j)]);
        }
        arr[i]=count+1;
    }
    return arr[n];
}
int main()
{
	int n;
	cin >> n;
    cout << minCount(n)<<endl;
	cout << minCount1(n)<<endl;
    cout << minCount2(n)<<endl;
}