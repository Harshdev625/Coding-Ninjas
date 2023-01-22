#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

class Pair
{
public:
    Node<int> *head;
    Node<int> *tail;

    Pair()
    {
        this->head = NULL;
        this->tail = NULL;
    }
};

Pair constructLL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    if (root->left == NULL && root->right == NULL)
    {
        Node<int> *node = new Node<int>(root->data);
        Pair ans;
        ans.head = node;
        ans.tail = node;
        return ans;
    }
    Pair left = constructLL(root->left);
    Pair right = constructLL(root->right);
    Node<int> *node = new Node<int>(root->data);
    Pair ans;
    if (left.tail == NULL)
    {
        ans.head = node;
    }
    else
    {
        left.tail->next = node;
        ans.head = left.head;
    }
    node->next = right.head;
    if (right.head == NULL)
    {
        ans.tail = node;
    }
    else
    {
        ans.tail = right.tail;
    }
    return ans;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    Pair ans = constructLL(root);
    return ans.head;
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
    Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}