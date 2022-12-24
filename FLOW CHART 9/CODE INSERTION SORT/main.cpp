#include <iostream>

using namespace std;

void insertionsort(int input[],int n){
   for(int i=1;i<n;i++){
   int current =input[i];
   for(int j=i-1;j>=0;j--){
    if(input[j]>current){
        input[j+1]=input[j];
        input[j]=current;
    }
    else{
        break;
    }
   }
   }
}

int main(){
    int n;
    cin>>n;
    int input[100000];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    insertionsort(input,n);
    for(int i=0;i<n;i++){
    cout<<input[i]<<" ";
   }
}

