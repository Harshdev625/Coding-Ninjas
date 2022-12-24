#include <iostream>
#include <cstring>

using namespace std;

void removeAllOccurrencesOfChar(char a[],char c){
    int b=strlen(a);
    int j=0;
    for(int i=0;i<=b;i++){
        if(a[i]!=c){
            a[j]=a[i];
            j++;
        }
        if(i==b){
            a[j]='\0';
        }
    }
}

int main(){
     int n = 1e6;
    char a[n];
    cin.getline(a, n);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(a,c);
    cout <<a;
}
