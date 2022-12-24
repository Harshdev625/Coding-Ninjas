#include <iostream>

using namespace std;

int findduplicate( int input[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j){
                if(input[i]==input[j]){
                return input[i];
                }
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int input[1000];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<findduplicate(input,n);
}
