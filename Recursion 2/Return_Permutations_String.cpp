#include <iostream>
#include <string>
using namespace std;
int returnPermutations(string input, string output[]){
    if(input.size() == 0){
        output[0] = "";
        return 1;
    }
    int i = 0, k=0;
    while(i < input.size()){
        string out[10000];
        string smallString = input.substr(0,i) + input.substr(i+1);
        int ans = returnPermutations(smallString, out);
        for(int j=0; j<ans; j++){
        	output[k++] = input[i]+out[j];
    	}
        i++;
    }
    return k;
}
int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
