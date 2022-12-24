#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector <TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;
    }
};
template <typename T>
TreeNode <T>* takeinput(){
    T data;
    cin>>data;
    TreeNode<T>* root = new TreeNode(data);
    queue <TreeNode<T>*> pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode<T>* front =pendingnode.front();
        pendingnode.pop();
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            T childdata;
            cin>>childdata;
            TreeNode<T>*childinfo = new TreeNode(childdata);
            front->children.push_back(childinfo);
            pendingnode.push(childinfo);
        }
    }
    return root;
}
template <typename T >
void pretraversal(TreeNode<T>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        pretraversal(root->children[i]);
    }
}
template <typename T>
void posttraversal(TreeNode<T>*root){
    if(root==NULL){
        return;
    }
    int i;
    for(i=0;i<root->children.size();i++){
        posttraversal(root->children[i]);
        
        //cout<<root->children[i]->data<<" ";
    }
    
    cout<<root->data<<" ";
    
}
int main(){
    TreeNode <int>* root = takeinput<int>();
    pretraversal(root);
    cout<<endl;
    posttraversal(root);
}