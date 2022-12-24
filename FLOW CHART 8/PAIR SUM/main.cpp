#include <iostream>


using namespace std;

void arrsum(int input[],int n,int x){
    int val=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x==input[i]+input[j]){

                val++;
            }
        }
    }
    cout<<val;
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
    arrsum(input,n,x);
}
