#include <iostream>
#include <string>
using namespace std;
int keypad(int num, string output[]){
    if(num==0 || num==1){
        output[0]="";
        return 1;
    }
    int t=keypad(num/10,output);
    int b=num%10;
    int l;
    string k;
    switch(b){
        case 0:
        l=1;
        k="";
        break;
        case 1:
        l=1;
        k="";
        break;
        case 2:
        l=3;
        k="abc";
        break;
        case 3:
        l=3;
        k="def";
        break;
        case 4:
        l=3;
        k="ghi";
        break;
        case 5:
        l=3;
        k="jkl";
        break;
        case 6:
        l=3;
        k="mno";
        break;
        case 7:
        l=4;
        k="pqrs";
        break;
        case 8:
        l=3;
        k="tuv";
        break;
        case 9:
        l=4;
        k="wxyz";
        break;
        default:
        break;
    }
    for(int i=0;i<t;i++){
        string s=output[i];
        for(int j=0;j<l;j++){
            output[j*t+i]=s+k[j];
        }
    }
    return l*t;
}
int main(){
    int num;
    cin >> num;
    string output[10000];
    output[0]="";
    int count = keypad(num, output);
    cout<<count<<endl;
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

