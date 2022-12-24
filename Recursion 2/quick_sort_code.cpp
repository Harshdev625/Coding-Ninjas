#include<iostream>
using namespace std;
int partition(int *input,int start,int end){
    int temp =input[start];
    int n=0;
    for(int i=start+1;i<=end;i++){
        if(input[i]<=temp){
            n++;
        }
    }
    input[start]=input[start+n];
    input[start+n]=temp;
    int i,j,temp1;
    for(i=start,j=end;i<=start+n-1 && j>=start+n+1;){
        if( input[i]<=temp){
            i++;
        }
        else if( input[j]>temp){
            j--;
        }
        else {
            temp1=input[i];
            input[i]=input[j];
            input[j]=temp1;
            i++;
            j--;
        }   
    }
    return start+n;
}
void quicksortfun(int *input,int start ,int end){
    if(start>=end){
        return;
    }
    int pivot = partition(input,start,end);
    quicksortfun(input,start,pivot-1);
    quicksortfun(input,pivot+1,end);
}
void quickSort(int *input,int n){
    quicksortfun(input,0,n-1);
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}
