#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    int data;
    vector <TreeNode<T>*> children ;
    TreeNode(T data){
        this->data=data;
    }
};
template <typename T>
TreeNode <T>* takeinput(){
    int data;
    cin>>data;
    TreeNode <T> * root = new TreeNode(data);
    queue <TreeNode<T>*> pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode <T>* front=pendingnode.front();
        pendingnode.pop();
        int child;
        cin>>child;
        for(int i=0;i<child;i++){
            T newchild;
            cin>>newchild;
            TreeNode <T>* childdata= new TreeNode(newchild);
            front->children.push_back(childdata);
            pendingnode.push(childdata);
        }
    }
    return root;
}
template <typename T>
T sumOfNodes(TreeNode<T>* root){
    if(root==NULL){
        return 0;
    }
    T sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=sumOfNodes(root->children[i]);
    }
    return sum;
}
int main(){
    TreeNode <int>*root =takeinput<int>();
    int ans= sumOfNodes<int>(root);
    cout<<ans;
}
