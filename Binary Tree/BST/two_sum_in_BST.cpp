#include <bits/stdc++.h> 
using namespace std;
// Following is the Binary Tree node structure
template <typename T>
class BinaryTreeNode {
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

void inorderTraversal(BinaryTreeNode<int>* root, vector<int> &inorder) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right,inorder);
}


bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorder;
    inorderTraversal(root,inorder);
    
    int size = inorder.size();
    int first = 0;
    int last = size-1;
    
    while (first < last) {
        int sum = inorder[first] + inorder[last];
        if (sum == target) {
            return true;
        }
        else if (sum > target) {
            last = last-1;
        }
        else first = first+1;
    }
    return false;
}