#include <iostream>

using namespace std;

void rotatearray(int input[],int n,int t){
    for(int k=0;k<t;k++){
        for(int i=0;i<n-1;i++){
            int a=input[i];
            input[i]=input[i+1];
            input[i+1]=a;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int input[100];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int t;
    cin>>t;
    rotatearray(input,n,t);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
}
