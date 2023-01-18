#include <iostream>
#include <queue>
#include "Binary_Tree.h"
using namespace std;
template <typename T>
BinaryTree<T> *mirror(BinaryTree<T> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    BinaryTree<T> *copy = root->left;
    root->left = root->right;
    root->right = copy;
    mirror(root->left);
    mirror(root->right);
    return root;
}
void print(BinaryTree<int> *root)
{
    queue<BinaryTree<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTree<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
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
    print(root);
    cout << endl;
    BinaryTree<int> *root1 = mirror<int>(root);
    print(root1);
}