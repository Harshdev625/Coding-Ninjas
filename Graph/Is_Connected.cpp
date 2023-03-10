#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&edges, int n, int start, vector<bool> & visited){
    for(int i=0; i<n; i++){
        if(i != start && edges[start][i] == 1 && !visited[i]){
            visited[i] = true;
            DFS(edges, n, i, visited);
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>>edges(v,vector<int>(v,0));
    for(int i=0; i<e; i++){
        int sv, lv;
        cin >> sv >> lv;
        edges[sv][lv] = edges[lv][sv] = 1;
    }
    vector<bool> visited(v);
    visited[0] = true;
    DFS(edges, v, 0, visited);
    bool isConnected=true;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            isConnected = false;
            break;
        }
    }
    cout << endl;
    isConnected ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}