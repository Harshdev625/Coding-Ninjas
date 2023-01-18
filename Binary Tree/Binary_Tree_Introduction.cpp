#include <iostream>
#include "Binary_Tree.h"
using namespace std;
int main()
{
    BinaryTree<int> *root = new BinaryTree<int>(1);
    BinaryTree<int> *node1 = new BinaryTree<int>(2);
    BinaryTree<int> *node2 = new BinaryTree<int>(3);
    root->left = node1;
    root->right = node2;
}