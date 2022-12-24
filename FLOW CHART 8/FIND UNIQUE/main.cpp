#include <iostream>

using namespace std;

int findunique( int input[] ,int n){
for(int i=0;i<n;i++){
    int j=0;
    for(j=0;j<n;j++){
            if(i!=j){
        if(input[i]==input[j]){
            break;
        }
      }
    }
    if( j==n){
        return input[i];
    }
}
}
int main(){
    int input[10000];
    int n;
    cin>>n;
 for(int i=0;i<n;i++){
    cin>>input[i];
 }


 cout<< findunique(input,n);
}
