#include <iostream>

using namespace std;

int cb(int input[],int n, int x){
    int s=0;
    int e=n-1;
    int m;
    while(s<=e){
        m=(e+s)/2;
    if(input[m]==x){
        return m;
    }
    else if(input[m]<x){
        s=m+1;
    }
    else{
        e=m-1;
    }
}
return -1;
}

int main()
{
    int n;
    cin>>n;
    int input[100000];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int x;
    cin>>x;
    cout<<cb(input,n,x);
}
