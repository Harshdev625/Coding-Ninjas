#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int,int>map;
    int max=0;
    for(int i=0;i<n;i++){
        map[a[i]]++;
        if(map[a[i]]>max){
            max=map[a[i]];
        }
    }
    int maxelement;
    for(int i=0;i<map.size();i++){
        if(map[a[i]]==max){
            maxelement=a[i];
            break;
        }
    }
    cout<<maxelement;
}