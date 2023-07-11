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

TreeNode<int>* convertToBalancedBST(int s, int e, vector<int> &inorder) {
    if (s>e) {
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode<int>* newNode = new TreeNode<int>(inorder[mid]);
    newNode->left = convertToBalancedBST(s,mid-1,inorder);
    newNode->right = convertToBalancedBST(mid+1,e,inorder);

    return newNode;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorder;
    inorderTraversal(root,inorder);

    int start = 0;
    int end = inorder.size()-1;

    return convertToBalancedBST(start,end,inorder);
}
