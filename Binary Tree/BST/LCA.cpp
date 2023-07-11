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

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	while (root != NULL) {
        
        if ((P->data > root->data) && (Q->data > root->data)) {
            root = root->right;
        }

        else if ((P->data < root->data) && (Q->data < root->data)) {
            root = root->left;
        }

        else return root; //i.e. (P->data > root->data) && (Q->data < root->data)
        //or vice versa

    }
}
