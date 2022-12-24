#include <iostream>
#include <queue>
#include "TreesNode.h"
using namespace std;
TreeNode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"Enter the root data: "<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue <TreeNode<int>*> pendingtreenode;
    pendingtreenode.push(root);
    while(!pendingtreenode.empty()){
        TreeNode<int>* front =pendingtreenode.front();
        pendingtreenode.pop();
        cout<<"Enter the number of chidren of "<< front->data<<endl;
        int child;
        cin>>child;
        for(int i=0;i<child;i++){
            int childdata;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childdata;
            TreeNode<int>* childoftreenode= new TreeNode<int>(childdata);
            front->children.push_back(childoftreenode);
            pendingtreenode.push(childoftreenode);
        }
    }
    return root;
}
void printnode(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printnode(root->children[i]);
    }
}
int main(){
    TreeNode<int>* root=takeinputlevelwise();
    printnode(root);
}
