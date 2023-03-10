#include <iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;
vector<int> getPathBFS(vector<vector<int> > edges, int n, int v1, int v2, vector<bool> visited){
    queue<int> q;
    unordered_map<int, int> mp;
    vector<int> res;
    q.push(v1);
    visited[v1]=true;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(i==t)continue;
            if(edges[t][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
                mp[i]=t;
                if(i==v2){
                    while(mp[i]!=v1){
                        res.push_back(i);
                        i=mp[i];
                    }
                    res.push_back(i);
                    res.push_back(mp[i]);
                    return res;
                }
            }
        }
    }
    return res;
}
int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int> > edges(v, vector<int>(v));
    for(int i=0; i<e; i++){
        int sv, lv;
        cin >> sv >> lv;
        edges[sv][lv] = edges[lv][sv] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    cout << endl;
    vector<bool> visited(v);
    vector<int> path = getPathBFS(edges, v, v1, v2, visited);
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }

    return 0;
}