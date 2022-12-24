#include <iostream>
#include <cstring>
using namespace std;
bool isPermutation(char str1[],char str2[]){
    int a[26]={0};
    int b[26]={0};
    int c=strlen(str1);
    int d=strlen(str2);
    if(c!=d){
        return false;
    }
    for(int i=0;i<c;i++){
        int e=str1[i]-'a';
        a[e]++;
    }
    for(int i=0;i<d;i++){
        int e=str2[i]-'a';
        b[e]++;
    }
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}