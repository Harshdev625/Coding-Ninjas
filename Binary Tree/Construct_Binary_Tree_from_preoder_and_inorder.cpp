#include <bits/stdc++.h>
#include "Binary_Tree.h"
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

BinaryTree<int> *buildtreehelper(int *pre, int preS, int preE, int *in, int inS, int inE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    root->left = buildtreehelper(pre, lPreS, lPreE, in, lInS, lInE);
    root->right = buildtreehelper(pre, rPreS, rPreE, in, rInS, rInE);
    return root;
}
BinaryTree<int> *buildtree(int *pre, int presize, int *in, int insize)
{
    return buildtreehelper(pre, 0, presize - 1, in, 0, insize - 1);
}
int main()
{
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTree<int> *root = buildtree(pre, size, in, size);
    print(root);
}