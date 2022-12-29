#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
void print (int **b,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}
void solution(int **a,int **b,int n,int r,int c){
    if(r==n-1 && c==n-1){
        b[r][c]=1;
        print(b,n);
        b[r][c]=0;
        return;
    }
    
    if(r<0 || c<0 || r>n-1 || c>n-1 || a[r][c]==0 ||b[r][c]==1){
        return;
    }
    b[r][c]=1;
    solution(a,b,n,r+1,c);
    solution(a,b,n,r,c+1);
    solution(a,b,n,r-1,c);
    solution(a,b,n,r,c-1);
    b[r][c]=0;
    return;
}
int main() {
    // your code goes here
    int n;
    cin>>n;
    int **a= new int*[n];
    for(int i=0;i<n;i++){
        a[i]= new int[n];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int **b= new int*[n];
    for(int i=0;i<n;i++){
        b[i]= new int[n];
        for(int j=0;j<n;j++){
            b[i][j]=0;
        }
    }
    solution(a,b,n,0,0);
    return 0;
}
