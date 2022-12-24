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
        this->data =data;
    }
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};
template <typename T>
TreeNode<T>* takeinput(){
    T data ;
    cin>>data;
    TreeNode <T> * root =new TreeNode<T>(data);
    queue <TreeNode<T>*> pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode <T>* front=pendingnode.front();
        pendingnode.pop();
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            T childdata;
            cin>>childdata;
            TreeNode<T>* childinfo = new TreeNode<T>(childdata);
            front->children.push_back(childinfo);
            pendingnode.push(childinfo);
        }
    }
    return root;
}
template <typename T>
void printtreenode(TreeNode<T> * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0 ;i<root->children.size();i++){
        if(i<root->children.size()-1 && i>=0){
            cout<<root->children[i]->data<<",";
        }
        else{
            cout<<root->children[i]->data;
            
        }
    }
    cout<<endl;
    for( int i=0;i<root->children.size();i++){
        printtreenode(root->children[i]);
    }
}
int main(){
    TreeNode<int>*root = takeinput<int>();
    printtreenode(root);
}