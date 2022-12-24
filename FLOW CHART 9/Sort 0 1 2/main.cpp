#include <iostream>

using namespace std;

void sort012(int input[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(input[j]>input[j+1]){
              int t=input[j];
              input[j]=input[j+1];
              input[j+1]=t;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int input[10000];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort012(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
}
