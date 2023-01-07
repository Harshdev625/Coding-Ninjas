#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int subsetsum(int a[],int n,int s,int sum){
    if(s==n){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    int count=0;
    if(sum-a[s]>=0){
        count += subsetsum(a,n,s+1,sum-a[s]);
    }
    count += subsetsum(a,n,s+1,sum);
    return count;
}
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,sum;
        cin>>n>>sum;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int count=0;
        cout<<subsetsum(a,n,0,sum)<<endl;
    }
    return 0;
}
