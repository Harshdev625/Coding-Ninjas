#include <iostream>
#include <climits>
using namespace std;

int findsecondlargest(int input[],int n){
    int l = INT_MIN, sl = INT_MIN;
    for(int i=0;i<n;i++){
        if(input[i] > l)
        {
            sl = l;
            l = input[i];
        }
        else if(input[i] > sl && input[i] != l)
        {
            sl = input[i];
        }
    }
    return sl;
}

int main()
{
    int n;
    cin>>n;
    int input[10000];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<findsecondlargest(input,n);
}
