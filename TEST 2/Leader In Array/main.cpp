#include <iostream>

using namespace std;

void leaderinarray(int a[],int len){
    for(int i=0;i<len;i++){
        int j=i+1;
            while(j<len){
            if(a[i]>=a[j]){
                j++;
            }
            else{
                break;
            }
            }
        if(j==len){
            cout<<a[i]<<" ";
        }
    }
}

/*void leaderinarray(int a[],int len){
    for(int i=0;i<len;i++){
        int j=i+1;
      //  if(a[i]>a[j]){
            while(j<len)
            {
            if(a[i]>=a[j])
            {
                j++;
            }
                else if(a[i]<a[j])
                    break;

            }

         //   }


        if(j==len){
            cout<<a[i]<<" ";
        }
    }
}*/


int main()
{
    int len;
    cin>>len;
    int a [1000];
    for(int i=0;i<len;i++){
        cin>>a[i];
    }
    leaderinarray(a,len);
}
