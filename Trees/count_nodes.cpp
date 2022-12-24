#include <iostream>
#include <queue>
#include "TreesNode.h"
using namespace std;
template <typename T>
TreeNode<T>* takeinput(){
    T rootdata;
    cin>>rootdata;
    TreeNode<T>* root=new TreeNode(rootdata);
    queue<TreeNode<T>*>pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode<T>*front=pendingnode.front();
        pendingnode.pop();
        int numofchild;
        cin>>numofchild;
        for(int i=0;i<numofchild;i++){
            T childdata;
            cin>>childdata;
            TreeNode<T>*child = new TreeNode<T>(childdata);
            front->children.push_back(child);
            pendingnode.push(child); 
        }
    }
    return root;
}
template <typename T>
void print(TreeNode<T>*root){
    if(root==NULL){
        return;
    }
    queue<TreeNode<T>*>pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode<T>*front=pendingnode.front();
        pendingnode.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<" ";
            pendingnode.push(front->children[i]);
        }
        cout<<endl;
    }
}
template <typename T>
int countnode(TreeNode<T>*root){
    if(root==NULL){
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=countnode(root->children[i]);
    }
    return ans;
}
int main(){
    TreeNode<int>*root=takeinput<int>();
    print(root);
    int ans=countnode(root);
    cout<<ans;
}