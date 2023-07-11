#include <bits/stdc++.h> 
using namespace std;
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
class BinaryTreeNode 
    {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
void inorderTraversal (BinaryTreeNode* root, vector<int> &inorder) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right,inorder);
}


int kthSmallest(BinaryTreeNode* root, int k) {
    vector<int> inorder;
    inorderTraversal(root,inorder);
    if (inorder.size() < k) {
        return -1;
    }

    return inorder[k-1];
}