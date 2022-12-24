#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;
    }
};
template <typename T>
TreeNode <T>* takeinput(){
    T data;
    cin>>data;
    TreeNode <T> * root = new TreeNode(data);
    queue <TreeNode<T>*> pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode <T>*front= pendingnode.front();
        pendingnode.pop();
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            T childdata;
        cin>>childdata;
        TreeNode <T>*newchild=new TreeNode(childdata);
        front->children.push_back(newchild);
        pendingnode.push(newchild);
        }
        
    }
    return root;
}
template <typename T>
TreeNode<T>* maxDataNode(TreeNode<T>* root){
    if(root==NULL){
        return root;
    }
    TreeNode<T>* max =root;
    for(int i=0;i<root->children.size();i++){
        TreeNode <T> * child =maxDataNode( root->children[i]);
        if(child->data > max->data){
            max=child;
        }
    }
    return max;
}
int main(){
    TreeNode<int>* root=takeinput<int>();
    int ans = maxDataNode<int>(root)->data;
    cout<<ans;
}