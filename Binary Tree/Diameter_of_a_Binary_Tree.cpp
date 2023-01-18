#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int,int> heightdiameter(BinaryTreeNode<int> *root)
{
    // Write our code here
    if (root == NULL)
    {
        pair<int,int>p(0,0);
        return p;
    }
    pair<int,int>left= heightdiameter(root->left);
    pair<int,int>right= heightdiameter(root->right);
    int lh=left.first;
    int ld=left.second;
    int rh=right.first;
    int rd=right.second;
    pair<int,int>ans;
    ans.first=1+max(lh,rh);
    ans.second=max(lh+rh,max(ld,rd));
    return ans;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int,int>p=heightdiameter(root);
    cout << p.first<<endl;
    cout << p.second<<endl;
}