#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
int postfix(string s){
    stack <int> s1;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            s1.push(s[i]-'0');
        }
        else{
            int op2=s1.top();
            s1.pop();
            int op1=s1.top();
            s1.pop();
            switch(s[i]){
                case '+':
                s1.push(op1+op2);
                break;
                case '-':
                s1.push(op1-op2);
                break;
                case '*':
                s1.push(op1*op2);
                break;
                case '/':
                s1.push(op1/op2);
                break;
                case '^':
                s1.push(pow(op1,op2));
                break;
            }
        }
    }
    return s1.top();
}
int main(){
    string s;
    cin>>s;
    cout<<postfix(s)<<endl;
}