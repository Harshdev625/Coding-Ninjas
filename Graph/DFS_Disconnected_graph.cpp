#include <bits/stdc++.h>
using namespace std;
void printDFS(int**arr,int startvertex,int verticies,bool*visited){
    cout<<startvertex<<endl;
    visited[startvertex]=true;
    for(int i=0;i<verticies;i++){
        if(i==startvertex){
            continue;
        }
        if(arr[startvertex][i]==1 && !visited[i]){
            printDFS(arr,i,verticies,visited);
        }
    }
}
void DFS(int**arr,int verticies){
    bool* visited= new bool[verticies];
    for(int i=0;i<verticies;i++){
        visited[i]=false;
    }
    for(int i=0;i<verticies;i++){
        if(!visited[i]){
            printDFS(arr,i,verticies,visited);
        }
    }
}
int main() {
    int verticies,edges;
    cin>>verticies>>edges;
    int**arr = new int*[verticies];
    for(int i=0;i<verticies;i++){
        arr[i] = new int[verticies];
        for(int j=0;j<verticies;j++){
            arr[i][j]=0;
        }
    }
    int first,second;
    for(int i=0;i<edges;i++){
        cin>>first>>second;
        arr[first][second]=1;
        arr[second][first]=1;
    }
    DFS(arr,verticies);
}
