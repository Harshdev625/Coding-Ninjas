#include <iostream>
#include <unordered_map>
using namespace std;
int pairSum(int *arr, int n) {
    unordered_map<int,int> map;
    int ans=0;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(map[-arr[i]]>0){
            map[arr[i]]--;           
            ans+=map[-arr[i]];
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans =pairSum(a, n);
    cout<<ans<<endl;
}