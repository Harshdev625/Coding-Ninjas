#include <iostream>

using namespace std;

int triplesum(int input[],int n,int x){
    int val=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
                for(int k=j+1;j<n;k++){
                    if(x==input[i]+input[j]+input[k]){
                        val++;
                }
            }
        }
    }
    return val;
}

int main()
{
    int n;
    int x;
    cin>>n;
    int input[100000];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cin>>x;
    cout<<triplesum(input,n,x);
    return 0;
}
