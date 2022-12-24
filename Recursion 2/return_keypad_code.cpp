#include <iostream>
#include <string>
using namespace std;
int keypad(int num, string output[]){
    if(num==0 || num==1 ){
        output[0]="";
        return 1;
    }
    int size =keypad( num/10,output);
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
    for(int i=0;i<size;i++){
        string extra=output[i];
        for(int j=0;j<length;j++){
            output[i+j*size]=extra+k[j];
        }
    }
    return size*length;
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
