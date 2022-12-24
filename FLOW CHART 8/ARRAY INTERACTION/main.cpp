#include <iostream>
#include <climits>

using namespace std;

void ar(int input1[],int input2[],int n1,int n2){
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(input1[i]==input2[j]){
                cout<<input1[i]<<" ";
                input2[j]=INT_MIN;
                break;
            }
        }
    }
}
int main()
{
    int n1;
    cin>>n1;
    int input1[100000];
    for(int i=0;i<n1;i++){
        cin>>input1[i];
    }
    int n2;
    cin>>n2;
    int input2[100000];
    for(int i=0;i<n2;i++){
        cin>>input2[i];
    }
    ar(input1,input2,n1,n2);
}
