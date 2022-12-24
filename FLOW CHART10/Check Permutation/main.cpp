#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void checkpermutation(char str1[],char str2[]){
    int c1=strlen(str1);
    int c2=strlen(str2);
    if(c1!=c2){
        cout<<"false";
    }
    for(int i=0;i<c1;i++){
        for(int j=1;j<c1;j++){
            if(str1[i]>str1[j]){
                char a1= str1[i];
                str1[i]=str1[j];
                str1[j]=a1;
            }
        }
    }
    for(int i=0;i<c2;i++){
        for(int j=1;j<c2;j++){
            if(str2[i]>str2[j]){
                char a2= str2[i];
                str2[i]=str2[j];
                str2[j]=a2;
            }
        }
    }
    if(strcmp(str1,str2)==0){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}

int main()
{
    int n=1e6;
    char str1[n];
    char str2[n];
    cin>>str1>>str2;

    checkpermutation(str1,str2);
}
