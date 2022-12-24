#include <iostream>

using namespace std;

void cmtsa(int input1[],int input2[],int input3[],int n1,int n2){
    int i,j=0;
    int k=0;
    while(i<n1 && j<n2){
            if(input1[i]>input2[j]){
                input3[k++]=input2[j];
                j++;
            }
            else{
                input3[k++]=input1[i];
                i++;
            }
        }

    while (i < n1)
        input3[k++] = input1[i++];
    while (j < n2)
        input3[k++] = input2[j++];
}

int main(){
    int n1;
    cin>>n1;
    int input1[100000];
    for(int i=0;i<n1;i++){
        cin>>input1[i];
    }
    int n2;
    cin>>n2;
    int input2[100000];
    for(int j=0;j<n2;j++){
        cin>>input2[j];
    }
    int input3[100000];
    cmtsa(input1,input2,input3,n1,n2);
    for(int i=0;i<n1+n2;i++){
        cout<<input3[i]<<" ";
    }
}

