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
string infixtoprefix(string str){
    stack <char> s1;
    string result;
    int b=str.size();
    for(int i=0,j=b-1;j>i;i++,j--){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    for(int i=0;i<str.length();i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')|| (str[i]>='0'&& str[i]<='9')){
            result+=str[i];
        }
        else if(str[i]==')'){
            s1.push(str[i]);
        }
        else if(str[i]=='('){
            while(!s1.empty() && s1.top()!=')'){
                result+=s1.top();
                s1.pop();
            }
            if(!s1.empty()){
                s1.pop();
            }
        }
        else{
            while(!s1.empty() && prec(s1.top())>=prec(str[i])){
                result+=s1.top();
                s1.pop();
            }
            s1.push(str[i]);
        }
        
    }
    while(!s1.empty()){
        result+=s1.top();
        s1.pop();
    }
    int c=result.size();
    for(int i=0,j=c-1;j>i;i++,j--){
        char temp=result[i];
        result[i]=result[j];
        result[j]=temp;
    }
    return result;
}
int main(){
    string str;
    cin>>str;
    cout<<infixtoprefix(str)<<endl;
}