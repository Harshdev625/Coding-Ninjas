#include <iostream>

using namespace std;

void pushzerosend(int input[],int n){

   int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(input[i] != 0)
        {
            input[k++] = input[i];
        }
    }

    while(k < n)
    {
        input[k++] = 0;
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
   pushzerosend(input,n);

   for(int i=0;i<n;i++){
    cout<<input[i]<<" ";
   }
}
