#include <iostream>
#include <string>
using namespace std;

void printKeypad1(int num,string output){
    if(num==0 | num==1){
        cout<<output<<endl;
        return;
    }
    int b=num%10;
    int length;
    string k;
    switch(b){
        case 0:
        length=1;
        k="";
        break;
        case 1:
        length=1;
        k="";
        break;
        case 2:
        length=3;
        k="abc";
        break;
        case 3:
        length=3;
        k="def";
        break;
        case 4:
        length=3;
        k="ghi";
        break;
        case 5:
        length=3;
        k="jkl";
        break;
        case 6:
        length=3;
        k="mno";
        break;
        case 7:
        length=4;
        k="pqrs";
        break;
        case 8:
        length=3;
        k="tuv";
        break;
        case 9:
        length=4;
        k="wxyz";
        break;
        default:
        break;
    }
    
    for(int i=0;i<length;i++){
        string extra=output;
    for(int j=0;j<output.size();j++){
        output[i +j*i]=extra+k;
        printKeypad1(num/10, output);
    }
    }
    
}
void printKeypad(int num){
    string output="";
    printKeypad1(num, output);
}
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
