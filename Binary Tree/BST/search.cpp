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


bool searchInBST(BinaryTreeNode *root, int x) {
    BinaryTreeNode* temp = root;

    while (temp != NULL) {
        if (temp->data == x) {
            return true;
        }

        else if (temp->data > x) {
            temp = temp->left;
        }

        else {
            temp = temp->right;
        }
    }

    return false;
}