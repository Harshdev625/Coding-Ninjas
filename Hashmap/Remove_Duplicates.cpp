#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> removeduplicates(int *a,int n){
    vector<int>output;
    unordered_map<int,bool>seen;
    for(int i=0;i<n;i++){
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans=removeduplicates(a,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}