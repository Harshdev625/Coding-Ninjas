#include <iostream>
#include "Binary_Tree.h"
using namespace std;
void printtree(BinaryTree<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL){
        cout<<"left->"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"right->"<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
BinaryTree<int>* takeinput(){
    cout<<"Enter input : ";
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTree<int>* root = new BinaryTree(data);
    BinaryTree<int>* left = takeinput();
    BinaryTree<int>* right = takeinput();
    root->left=left;
    root->right=right;
    return root;
}
int main(){
    BinaryTree<int>*root = takeinput();
    /*BinaryTree<int>*node1 = new BinaryTree<int>(2);
    BinaryTree<int>*node2 = new BinaryTree<int>(3);
    root->left=node1;
    root->right=node2;*/
    printtree(root);

}