#include <iostream>
#include <string>
using namespace std;
void permutations(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    for(int i=0; i<input.size(); i++){
        string smallString = input.substr(0,i) + input.substr(i+1);
        permutations(smallString, input[i]+output);
    }
}
void printPermutations(string input){
	string output="";
    permutations(input, output);
}
int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}