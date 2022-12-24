#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector <TreeNode <T>*> children;
    TreeNode(T data){
        this->data=data;
    }
};
template <typename T>
TreeNode <T>* takeinput(){
    T data;
    cin>>data;
    TreeNode <T> *root = new TreeNode<T> (data);
    queue <TreeNode<T>*> pendingtreenode;
    pendingtreenode.push(root);
    while(!pendingtreenode.empty()){
        TreeNode <T>* front = pendingtreenode.front();
        pendingtreenode.pop();
        int child;
        cin>>child;
        for(int i=0;i<child;i++){
            T childdata;
            cin>>childdata;
            TreeNode <T>* newchild =new TreeNode(childdata);
            front->children.push_back(newchild);
            pendingtreenode.push(newchild);
        }
    }
    return root;
}
template <typename T>
void print(TreeNode<T>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    queue <TreeNode<T>*> pendingnode;
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data;
        pendingnode.push(root->children[i]);
        if(i<root->children.size()-1){
            cout<<",";
        }
    }
    cout<<endl;
    for(;!pendingnode.empty();){
        for(int j=0;j<pendingnode.size();j++){
        cout<<pendingnode.front()->data<<":";
        for(int i=0;i<pendingnode.front()->children.size();i++){
        cout<<pendingnode.front()->children[i]->data;
        pendingnode.push(pendingnode.front()->children[i]);
        if(i<pendingnode.front()->children.size()-1){
            cout<<",";
        }
        }
        cout<<endl;
        pendingnode.pop();
    }
    }
    // APPROACH 2
    if(root ==NULL){
        return;
    }
    queue <TreeNode<int>*>pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        TreeNode<int>*front=pendingnode.front();
        pendingnode.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            if(i==front->children.size()-1){
                cout<<front->children[i]->data;
                pendingnode.push(front->children[i]);
            }
            else{
                cout<<front->children[i]->data<<",";
                pendingnode.push(front->children[i]);
            }
        }
        cout<<endl;
    }
}
int main(){
    TreeNode <int>*root = takeinput<int>();
    print(root);
}