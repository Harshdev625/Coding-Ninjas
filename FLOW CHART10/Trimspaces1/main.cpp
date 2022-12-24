#include <iostream>
#include <cstring>

using namespace std;
int length(char arr[]){
    int a=0;
    for(int i=0;arr[i]!='\0';i++){
    a++;
    }
    return a;
}
void trimspaces(char arr[]){
    int a=length(arr);
    for(int i=0;i!=a;i++ ){
        for(int j=0;j!=a;j++){
        if(arr[j]==' '){
            char b=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=b;
        }
    }
}
}
int main(){
    char arr[1000000];
    cin.getline(arr,1000000);
    trimspaces(arr);
    cout<<arr<<endl;
}
