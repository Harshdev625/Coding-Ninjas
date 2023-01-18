#include <iostream>
#include "Binary_Tree.h"
#include <queue>
using namespace std;
BinaryTree<int> *takeinput()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree(data);
    queue<BinaryTree<int> *> pendingnode;
    pendingnode.push(root);
    while (!pendingnode.empty())
    {
        BinaryTree<int> *front = pendingnode.front();
        pendingnode.pop();
        int leftchild;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTree<int> *left = new BinaryTree(leftchild);
            front->left = left;
            pendingnode.push(left);
        }
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

BinaryTree<int> *buildtreehelper(int *postOrder, int *inOrder, int postStart, int postEnd, int inStart, int inEnd)
{
    if (inStart > inEnd)
    {
        return NULL;
    }
    int rootData = postOrder[postEnd];
    int rootIndex = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lPostStart = postStart;
    int lInStart = inStart;
    int lInEnd = rootIndex - 1;
    int lPostEnd = lPostStart + lInEnd - lInStart;
    int rPostStart = lPostEnd + 1;
    int rPostEnd = postEnd - 1;
    int rInStart = rootIndex + 1;
    int rInEnd = inEnd;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    BinaryTree<int> *leftSubTree = buildtreehelper(postOrder, inOrder, lPostStart, lPostEnd, lInStart, lInEnd);
    BinaryTree<int> *rightSubTree = buildtreehelper(postOrder, inOrder, rPostStart, rPostEnd, rInStart, rInEnd);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
}
BinaryTree<int> *buildtree(int *post, int presize, int *in, int insize)
{
    return buildtreehelper(post, in, 0, presize - 1, 0, insize - 1);
}
int main()
{
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> post[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTree<int> *root = buildtree(post, size, in, size);
    print(root);
}