#include <iostream>
#include "TreesNode.h"
using namespace std;
TreeNode <int>* TakeInput(){
    int rootdata;
    cout<<"Enter data:";
    cin>>rootdata;
    TreeNode <int>* root = new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter num of children of : "<< rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode <int>* child = TakeInput();
        root->children.push_back(child);
    }
    return root;
} 
void printNode(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printNode(root->children[i]);
    }
}
int main(){
    /*TreeNode<int>*root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);*/
    TreeNode<int>*root = TakeInput();
    printNode(root);
}