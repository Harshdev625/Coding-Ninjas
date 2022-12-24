#include <iostream>
#include "Binary_Tree.h"
#include <queue>
using namespace std;
BinaryTree<int>* takeinput(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTree<int>*root=new BinaryTree(data);
    queue <BinaryTree<int>*> pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        BinaryTree<int>* front = pendingnode.front();
        pendingnode.pop();
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTree<int>* left=new BinaryTree(leftchild);
            front->left=left;
            pendingnode.push(left);
        }
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            BinaryTree<int>* right=new BinaryTree(rightchild);
            front->right=right;
            pendingnode.push(right);
        }
    }
    return root;
}
void print(BinaryTree<int>*root){
    /*if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	print(root->left);
	print(root->right);*/
    queue<BinaryTree<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTree<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTree<int>* buildtreehelper(int *pre , int preS , int preE,int* in , int inS ,int inE){
    /*if(pres>pree){
        return NULL;
    }
    int rootdata=pre[pres];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++){
        if(rootdata=in[i]){
            rootindex=i;
            break;
        }
    }
    int lpres=pres+1;
    int lins=ins;
    int line=rootindex-1;
    int lpree=line-lins+lpres;
    int rpres=lpree+1;
    int rins=rootindex+1;
    int rpree=pree;
    int rine=ine;
    BinaryTree<int>* root =new BinaryTree<int>(rootdata);
    BinaryTree<int>* leftSubTree = buildtreehelper(pre , lpres , lpree, in ,  lins , line);
    BinaryTree<int>* rightSubTree = buildtreehelper(pre , rpres , rpree, in , rins ,rine);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;*/
    if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
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
	BinaryTree<int>*  root = new BinaryTree<int>(rootData);
	root->left = buildtreehelper(pre, lPreS, lPreE,in , lInS, lInE);
	root->right = buildtreehelper(pre, rPreS, rPreE,in , rInS, rInE);
	return root;
}
BinaryTree <int>* buildtree(int* pre, int presize , int* in ,int insize){
    return buildtreehelper(pre , 0 ,presize-1, in , 0 ,insize-1);
}
int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTree<int> *root = buildtree(pre, size, in, size);
    print(root);
}