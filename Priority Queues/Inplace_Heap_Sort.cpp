#include <bits/stdc++.h>
using namespace std;
void buildheap(int arr[],int n){
    for(int i=1;i<n;i++){
        int childindex=i;
        while(childindex>0){
            int parentindex=(childindex-1)/2;
            if(arr[childindex]<arr[parentindex]){
                swap(arr[childindex],arr[parentindex]);
            }
            else{
                break;
            }
            childindex=parentindex;
        }
    }
    int size=n;
    while(size>1){
        swap(arr[0],arr[size-1]);
        size--;
        int parentindex=0;
        while(parentindex<size){
            int leftchildindex=2*parentindex+1;
            int rightchildindex=2*parentindex+2;
            int minindex=-1;
            if(leftchildindex<size && rightchildindex<size){
                if(arr[leftchildindex]<arr[rightchildindex]){
                    minindex=leftchildindex;
                }
                else{
                    minindex=rightchildindex;
                }
            }
            else if(leftchildindex<size){
                minindex=leftchildindex;
            }
            else if(rightchildindex<size){
                minindex=rightchildindex;
            }
            if(minindex!=-1 && arr[parentindex]>arr[minindex]){
                swap(arr[parentindex],arr[minindex]);
            }
            else{
                break;
            }
            parentindex=minindex;
        }
    }
}
void inplaceheapsort(int arr[], int n){
    buildheap(arr,n);
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    inplaceheapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}