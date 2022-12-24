#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char a[]){
    int c=strlen(a);
    int k=0;
    for(int i=0;i<=c;i++){
        if(a[i]==' '|| a[i]=='\0'){
            int j=i-1;

             while(j>k){
                char b=a[k];
                a[k]=a[j];
                a[j]=b;
                k++;
                j--;
        }
        k=i+1;
        }



    }
}
/*void reverseEachWord(char a[]){
    int c=strlen(a);
    int k=0;
    int i=0;
    //for(int i=0;i<c;i++){
    while(i<=c){
        if(a[i]==' ' || a[i] == '\0'){
            int j=i-1;

             while(j>k){
                char b=a[j];
                a[j]=a[k];
                a[k]=b;
                k++;
                j--;
        }
        k=i+1;
    }
        i++;
}
}*/

int main()
{
    int n = 1e6;
    char a[n];
    cin.getline( a,n);
    reverseEachWord(a);
    cout <<a;
}

