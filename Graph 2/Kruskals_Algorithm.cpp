#include <bits/stdc++.h>
using namespace std;
class Edges{
    public:
    int source;
    int destination;
    int weight;
};
bool compare(const Edges e1,const Edges e2){
    return e1.weight<e2.weight;
}
int getparent(vector<int>&parent,int index){
    while(parent[index]!=index){
        index=parent[index];
    }
    return index;
}
void kruskal(vector<Edges>&edge,int v,int e){
    sort(edge.begin(),edge.end(),compare);
    vector<Edges>MST;
    vector<int>parent(v);
    for(int i=0;i<v;i++)parent[i]=i;
    int count=0,i=0;
    while(count<v-1){
        int p1=getparent(parent,edge[i].source);
        int p2=getparent(parent,edge[i].destination);
        if(p1!=p2){
            MST.push_back(edge[i]);
            count++;
            parent[p1]=p2;
        }
        i++;
    }
    for(int i=0;i<v-1;i++){
        if(MST[i].source<MST[i].destination){
            cout<<MST[i].source<<" "<<MST[i].destination<<" "<<MST[i].weight<<endl;
        }
        else{
            cout<<MST[i].destination<<" "<<MST[i].source<<" "<<MST[i].weight<<endl;
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<Edges>edge(e);
    int source,destination,weight;
    for(int i=0;i<e;i++){
        cin>>source>>destination>>weight;
        edge[i].source = source;
        edge[i].destination= destination;
        edge[i].weight = weight;
    }
    kruskal(edge,v,e);
}