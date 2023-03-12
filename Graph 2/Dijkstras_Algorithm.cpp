#include <bits/stdc++.h>
using namespace std;
int findmindist(vector<int>&distance,vector<bool>&isvisited,int v){
    int minvertex=-1;
    for(int i=0;i<v;i++){
        if(!isvisited[i] && (minvertex==-1 ||distance[i]<distance[minvertex]))minvertex=i;
    }
    return minvertex;
}
void dijkstras(vector<vector<int>>&edge,int v){
    vector<bool>isvisited(v,false);
    vector<int>distance(v,INT_MAX);
    distance[0]=0;
    for(int i=0;i<v-1;i++){
        int minvertex=findmindist(distance,isvisited,v);
        isvisited[minvertex]=true;
        for(int j=0;j<v;j++){
            if(edge[minvertex][j]!=0 && !isvisited[j]){
                if((edge[minvertex][j]+distance[minvertex])<distance[j]){
                    distance[j]=edge[minvertex][j]+distance[minvertex];
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>edge(v,vector<int>(v,0));
    int sv,ev,weight;
    for(int i=0;i<e;i++){
        cin>>sv>>ev>>weight;
        edge[sv][ev]=edge[ev][sv]=weight;
    }
    dijkstras(edge,v);
}