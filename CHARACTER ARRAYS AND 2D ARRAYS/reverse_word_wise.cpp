#include <iostream>
#include <cstring>
using namespace std;
void reverseStringWordWise(char input[]){
    int l=strlen(input);
    for(int i=0,j=l-1;i<j;i++,j--){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
    }
    int j=0;
    for(int i=0;i<=l;i++){
        if(input[i]==' '||input[i]=='\0'){
            int k=i-1;
            for(;k>j;k--,j++){
            char temp=input[j];
            input[j]=input[k];
            input[k]=temp; 
            }
            j=i+1;
        }
    }
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
