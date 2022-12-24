#include <iostream>
#include <queue>
#include "Binary_Tree.h"
using namespace std;
template <typename T>
int countnode(BinaryTree<T>*root){
    if(root==NULL){
        return 0;
    }
    int ans=1;
    ans+=countnode(root->left);
    ans+=countnode(root->right);
    return ans;
}
void print(BinaryTree<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" :- ";
    if(root->left!=NULL){
        cout<<"left->"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"right->"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
BinaryTree<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"Enter root data : "<<endl;
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
        cout<<"Enter left chid "<<front->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTree<int>*left = new BinaryTree(leftchild);
            front->left=left;
            pendingnode.push(left);
        }
        cout<<"Enter right chid "<<front->data<<endl;
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
    //print(root);
    int ans =countnode<int>(root);
    cout<<ans;
}