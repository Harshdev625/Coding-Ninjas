#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&edges,vector<bool>&isvisited,int s,int n){
    if(isvisited[s]){
        return;
    }
    isvisited[s]=true;
    for(int i=0;i<n;i++){
        if(i!=s && edges[s][i]==1 && !isvisited[i]){
            dfs(edges,isvisited,i,n);
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>edges(v,vector<int>(v,0));
    int sv,ev;
    while(e--){
        cin>>sv>>ev;
        edges[sv][ev]=edges[ev][sv]=1;
    }
    vector<bool>isvisited(v,false);
    int count=0;
    for(int i=0;i<v;i++){
        if(!isvisited[i]){
            dfs(edges,isvisited,i,v);
            count++;
        }
    }
    cout<<count<<endl;
}