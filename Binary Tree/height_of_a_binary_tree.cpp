#include <iostream>
#include <queue>
#include "Binary_Tree.h"
using namespace std;
template <typename T>
void inordertraversal(BinaryTree<T>* root){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}
template <typename T>
void preordertraversal(BinaryTree<T>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left); 
    preordertraversal(root->right);
}
template <typename T>
void postordertraversal(BinaryTree<T>* root){
    if(root==NULL){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}
BinaryTree<int>* takeinputlevelwise(){
    int rootdata;
    //cout<<"Enter root data : "<<endl;
    cin>>rootdata;
    if(rootdata==-1){
    return NULL;
    }
    BinaryTree<int>* root = new BinaryTree<int>(rootdata);
    queue <BinaryTree<int>*> pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        BinaryTree<int>*front =pendingnode.front();
        pendingnode.pop();
        //cout<<"Enter left chid "<<front->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTree<int>*left = new BinaryTree(leftchild);
            front->left=left;
            pendingnode.push(left);
        }
        //cout<<"Enter right chid "<<front->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            BinaryTree<int>*right = new BinaryTree(rightchild);
            front->right=right;
            pendingnode.push(right);
        }
    }
    return root;
}
int main(){
    BinaryTree<int>*root = takeinputlevelwise();
    inordertraversal(root);
    cout<<endl;
    preordertraversal(root);
    cout<<endl;
    postordertraversal(root);
    cout<<endl;
}