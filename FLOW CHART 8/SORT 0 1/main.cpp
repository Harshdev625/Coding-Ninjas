#include <iostream>

using namespace std;

void sort01(int input[],int n){
    int t;
    int i=0;

    int j=n-1;
    while (i<j)
    {
       if(input[i]==0)
        i++;
       else if(input[j]==1)
           j--;
        else
        {
            t=input[i];
            input[i]=input[j];
            input[j]=t;
        }
    }
}
int main()
{
   int n;
   cin>>n;
   int input[100000];
   for(int i=0;i<n;i++){
    cin>>input[i];
   }
   sort01(input,n);
}
