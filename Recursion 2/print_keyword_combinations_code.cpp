#include <iostream>
#include <string>
using namespace std;
void printKeypad1(int num,string out){
    if(num==1 || num==0){
        cout<<out<<endl;
        return;
    }
    string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s=arr[num%10];
    for(int i=0;i<s.size();i++){
        printKeypad1(num/10,s[i]+out);
    } 
}
void printKeypad(int num){
    string out;
    printKeypad1(num,out);
}
int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}
