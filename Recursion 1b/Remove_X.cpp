#include <iostream>
#include <cstring>
using namespace std;
void removeX(char input[]){
    int b=strlen(input);
    if(b==0){
        return;
    }
    removeX(input+1);
    if(input[0]=='x'){
        for(int i=0;i<b;i++){
            input[i]=input[i+1];
        }
    }
  
}
int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
