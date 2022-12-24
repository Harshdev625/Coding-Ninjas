#include <iostream>
#include <cstring>
using namespace std;
bool checkPalindrome(char str[]){
    int b=strlen(str)-1;
    for(int i=0;i<=b;i++,b--){
        if(str[i]!=str[b]){
            return false;
        }
    }
    return true;
}
int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}