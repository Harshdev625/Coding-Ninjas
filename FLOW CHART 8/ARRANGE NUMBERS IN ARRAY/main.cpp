#include <iostream>
using namespace std;

{
        int i=0;
    int j=(n-1)/2;
    int val=1;
    while(i<=j){
        arr[i]=val;
        val+=2;
        i++;
    }
    if(n%2==0){
        val=n;
        while(val){
            arr[i]=val;
            val-=2;
            i++;
        }
    }
    else{
        val=n-1;
        while(val){
            arr[i]=val;
            val-=2;
            i++;
        }
    }

