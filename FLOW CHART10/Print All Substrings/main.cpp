#include <iostream>
#include <cstring>
using namespace std;

void printallsubstrings(char a[]){
    int b=0;
    for(int i=0;a[i]!='\0';i++){
       b++;
    }
   for(int i=0;i<b;i++){
    for(int j=i;j<b;j++){
      for(int k=i;k<=j;k++){
         cout<<a[k];
      }
       cout<<endl;
    }

   }
}
int main()
{
   char a[10000];
   cin.getline(a,10000);
   printallsubstrings(a);
}
