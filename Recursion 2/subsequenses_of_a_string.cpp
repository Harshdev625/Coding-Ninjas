#include <iostream>
#include <cmath>
using namespace std;
int subsequence(string input, string output[]){
    if(input.empty()){
       // output[0]="";
        return 1;
    }
    string small=input.substr(1);
    int size=subsequence(small,output);
    for(int i=0;i<size;i++){
        output[i+size]=input[0]+output[i];
    }
    return 2*size;
}
int main(){
    string input;
    cin>>input;
    int b=input.size();
    int c=pow(2,b);
    string *output =new string[c];
    int a=subsequence(input,output);
    for(int i=0;i<a;i++){
        cout<<output[i]<<endl;
    }
}