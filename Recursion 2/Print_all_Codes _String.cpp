#include <bits/stdc++.h>
using namespace std;
void possibleCodes(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    char ch1 = ( input[0] - '0' ) + 'a' - 1;
    possibleCodes(input.substr(1), output+ch1);
    if(input.length() >= 2){
        int number = (input[0] - '0')*10 + (input[1] - '0');
        if(number >= 10 && number <= 26){
         	char ch2 = number + 'a' - 1;
    		possibleCodes(input.substr(2), output+ch2);     
        } 
    }
}
void printAllPossibleCodes(string input) {
    string output="";
    possibleCodes(input, output);
}
int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
