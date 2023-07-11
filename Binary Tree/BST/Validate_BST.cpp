#include <bits/stdc++.h>
using namespace std;

//Following is the Binary Tree node structure:

class BinaryTreeNode {
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

// *************************************************************/
// another method is to print the tree in inorder and push it in a vector and check if it's sorted.
bool isBST(BinaryTreeNode *root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->data >= min && root->data <= max) {
        bool leftans = isBST(root->left,min,root->data);
        bool rightans = isBST(root->right,root->data,max);
        return leftans && rightans;
        //if both the tree on sides are correct, it will return true else return false
    }

    else return false;
    //for the case when condition with the root is not satisfied.
}


bool validateBST(BinaryTreeNode *root) {
    return isBST(root,INT_MIN,INT_MAX);
}