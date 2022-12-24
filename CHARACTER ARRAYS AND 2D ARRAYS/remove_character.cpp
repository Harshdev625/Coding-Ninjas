#include <iostream>
#include <cstring>
using namespace std;
void removeAllOccurrencesOfChar(char input[], char c){
    int b=strlen(input);
    for(int i=0;i<b;){
        if(input[i]==c){
            int j;
            for(j=i;j<b;j++){
                input[j]=input[j+1];
            }
            input[j]='\0';
        }
        else{
            i++;
        }
    }
}
int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}