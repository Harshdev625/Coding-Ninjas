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
TreeNode<T>* takeinput(){
    T data;
    cin>>data;
    TreeNode<T>* root = new TreeNode(data);
    queue <TreeNode<T>*> pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode <T>* front = pendingnode.front();
        pendingnode.pop();
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            T childdata;
            cin>>childdata;
            TreeNode <T>* childinfo = new TreeNode(childdata);
            front->children.push_back(childinfo);
            pendingnode.push(childinfo);
        }
    }
    return root;
}
template <typename T>
int getLeafNodeCount(TreeNode<T>* root) {
    if(root==NULL){
        return 0;
    }
    int depth=0;
    for(int i=0;i<root->children.size();i++){
        depth+=getLeafNodeCount( root->children[i]);

    }
    if(root->children.size()==0){
        return depth+1;
    }
    return depth;
}
int main(){
    TreeNode<int>* root =takeinput<int>();
    int ans=getLeafNodeCount<int>(root);
    cout<<ans;
}