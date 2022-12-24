#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixtopostfix(string s){
    stack <char> s1;
    string result;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result+=s[i];
        }
        else if(s[i]=='('){
            s1.push(s[i]);
        }
        else if(s[i]==')'){
            while(!s1.empty() && s1.top()!='('){
                result+=s1.top();
                s1.pop();
            }
            if(!s1.empty()){
                s1.pop();
            }
        }
        else{
            while(!s1.empty() && prec(s1.top())>prec(s[i])){
                result+=s1.top();
                s1.pop();
            }
            s1.push(s[i]);
        }
        
    }
    while(!s1.empty()){
        result+=s1.top();
        s1.pop();
    }
    return result;
}
int main(){
    string s;
    cin>>s;
    cout<<infixtopostfix(s)<<endl;
}
