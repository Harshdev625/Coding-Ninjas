#include <iostream>

using namespace std;
void replacecharacter(char str[],char c1,char c2){
    int t;
    for(int i=0;i!='/0';i++){
        t++;
    }
    for(int i=0;i<t;i++){
        if(str[i]==c1){
            str[i]= c2;
        }
    }
}

int main()
{
    int n=1e6;
    char str[n];
    cin>>str;
    char c1;
    char c2;
    cin>>c1>>c2;
    replacecharacter(str,c1,c2);
    cout<<str;
}
