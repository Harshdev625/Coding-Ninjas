#include <iostream>
#include <queue>
#include "Binary_Tree.h"
using namespace std;
template <typename T>
bool findanode(BinaryTree<T> *root, int n)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == n)
    {
        return true;
    }
    return findanode(root->left, n) || findanode(root->right, n);
}
void print(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " :- ";
    if (root->left != NULL)
    {
        cout << "left->" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "right->" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}
BinaryTree<int> *takeinputlevelwise()
{
    int rootdata;
    // cout<<"Enter root data : "<<endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int>(rootdata);
    queue<BinaryTree<int> *> pendingnode;
    pendingnode.push(root);
    while (!pendingnode.empty())
    {
        BinaryTree<int> *front = pendingnode.front();
        pendingnode.pop();
        // cout<<"Enter left chid "<<front->data<<endl;
        int leftchild;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTree<int> *left = new BinaryTree(leftchild);
            front->left = left;
            pendingnode.push(left);
        }
        // cout<<"Enter right chid "<<front->data<<endl;
        int rightchild;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTree<int> *right = new BinaryTree(rightchild);
            front->right = right;
            pendingnode.push(right);
        }
    }
    return root;
}
int main()
{
    BinaryTree<int> *root = takeinputlevelwise();
    // print(root);
    int n;
    cin >> n;
    findanode(root, n) ? cout << "true" : cout << "false";
}