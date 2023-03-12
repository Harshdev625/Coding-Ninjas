#include <bits/stdc++.h>
using namespace std;
int findminvertex(vector<int>&weight,vector<bool>&isvisited,int v){
    int minvertex=-1;
    for(int i=0;i<v;i++){
        if(!isvisited[i] && (minvertex==-1 ||weight[i]<weight[minvertex]))minvertex=i;
    }
    return minvertex;
}
void prims(vector<vector<int>>&edges,int v){
    vector<bool>isvisited(v,false);
    vector<int>weight(v,INT_MAX);
    vector<int>parent(v,-1);
    weight[0]=0;
    for(int i=0;i<v-1;i++){
        int minvertex=findminvertex(weight,isvisited,v);
        isvisited[minvertex]=true;
        for(int j=0;j<v;j++){
            if(edges[minvertex][j]!=0 && !isvisited[j]){
                if(weight[j]>edges[minvertex][j]){
                    weight[j]=edges[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }
    for(int i=1;i<v;i++){
        if(parent[i] < i){
            cout<<parent[i]<<" "<< i <<" "<< weight[i]<<endl;
        } else {
            cout<<i<<" "<<parent[i]<<" "<< weight[i]<<endl;
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>edges(v,vector<int>(v,0));
    int sv,ev,w;
    while(e--){
        cin>>sv>>ev>>w;
        edges[sv][ev]=edges[ev][sv]=w;
    }
    prims(edges,v);
}