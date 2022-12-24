#include <iostream>
#include <cstring>
using namespace std;

bool checkpalindrome(char str[]){
     int c=0;
    for(int i=0; str[i]!='\0'; i++){
        c++;
    }
    for(int i=0; i<=c/2; i++){
        if(str[i]!=str[c-i-1]) return false;
    }
   return true;
}

int main()
{
   int n=1e6;
   char str[n];
   cin>>str;
   cout<<checkpalindrome(str);

}
