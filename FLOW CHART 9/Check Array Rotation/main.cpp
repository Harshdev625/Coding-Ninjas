#include <iostream>

using namespace std;

int arrayrotatecheck(int input[],int n){
    if(n=1){
        return 0;
    }
    else{
    for(int i=0;i<n;i++){
        int j=i+1;
        if(input[i]>input[j]){
            return j;
        }
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
    cout<<arrayrotatecheck(input,n);

}
