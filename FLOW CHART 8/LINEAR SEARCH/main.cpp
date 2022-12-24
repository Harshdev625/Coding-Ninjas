#include <iostream>

using namespace std;

int linearsearch(int arr[],int n,int x){
    int i=0;
    while(i<n){
        if(arr[i]==x){
            return i;
        }
        i++;
    }
     return -1;
    }
int main()
{
    int t;
    cin>>t;
    while(t){
        int input[100000];
        int n;
        int i=0;
        cin>>n;
        while(i<n){
            cin>>input[i];
            i++;
        }
        int x;
        cin>>x;
        cout<<linearsearch(input,n,x)<<endl;
        t--;
    }
    return 0;
}
