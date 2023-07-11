#include <bits/stdc++.h> 
using namespace std;

template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void inorderTraversal(TreeNode<int>* root, vector<int> &inorder) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right,inorder);
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorder;
    inorderTraversal(root,inorder);
    int size = inorder.size();

    //creating first node outside so that it is not lost while returning
    TreeNode<int>* ansRoot = new TreeNode<int>(inorder[0]);
    //a pointer to the root node of answer is created
    TreeNode<int>* curr = ansRoot;
    int index = 1;
    //same processing for the rest of the nodes
    while (index <= size-1) {
        int data = inorder[index];
        TreeNode<int>* newNode = new TreeNode<int>(data);
        curr->right = newNode;
        curr->left = NULL;
        curr = newNode;
        index++;
    }

    //last nodes values are being set
    curr->left = NULL;
    curr->right = NULL;
    return ansRoot;
}
