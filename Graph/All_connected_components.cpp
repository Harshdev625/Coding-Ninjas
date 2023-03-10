#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&edges,vector<bool>&isvisited,int s,vector<int>&v,int n){
    if(isvisited[s]){
        return;
    }
    isvisited[s]=true;
    v.push_back(s);
    for(int i=0;i<n;i++){
        if(i!=s && edges[s][i]==1 && !isvisited[i]){
            dfs(edges,isvisited,i,v,n);
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
    vector<vector<int>>res;
    for(int i=0;i<v;i++){
        vector<int>ans;
        if(!isvisited[i]){
            dfs(edges,isvisited,i,ans,v);
            sort(ans.begin(),ans.end());
            res.push_back(ans);
        }
    }
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}