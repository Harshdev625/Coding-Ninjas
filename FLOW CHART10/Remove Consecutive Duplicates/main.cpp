#include <iostream>
#include <cstring>
using namespace std;

void rcd(char a[]){
    int b=strlen(a);
        int j=0;
        for(int i=0;i<b;i++){

          if(i==0){
            a[j]=a[i];
            j++;
           }
           else{
            if(a[i-1]!=a[i]){
                a[j]=a[i];
                j++;
           }
       }
       if(i==b-1){
        a[j]='\0';
       }
    }
  }

int main(){
    int n=1e6;
    char a[n];
    cin>>a;
    rcd(a);
    cout<<a;
}
