#include <iostream>
#include <cstring>
using namespace std;
void pairStar(char input[]){
    if(strlen(input)<=1){
        return;
    }
    pairStar(input+1);
    if(input[0]==input[1]){
        int a=strlen(input);
        for(int i=a;i>0;i--){
            input[i+1]=input[i];
        }
        input[1]='*';
        return ;
    }
}
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
