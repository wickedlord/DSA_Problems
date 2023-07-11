#include <bits/stdc++.h> 
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
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


pair<int,int> predecessorSuccessor(BinaryTreeNode* root, int key)
{
    BinaryTreeNode* temp = root;
    int pred = -1;
    int succ = -1;

    //finding key
    while (temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;  //for in case right side is null ----1
            temp = temp->left;
        }
        else {
            pred = temp->data;  //for in case left side is null ----2
            temp = temp->right;
        }
    }

    //pred and succ
    BinaryTreeNode* leftTree = temp->left;
    while (leftTree != NULL) {
        pred = leftTree->data;  //if there was no left part, then pred would have nothing (1)
        leftTree = leftTree->right;
    }
    BinaryTreeNode* rightTree = temp->right;
    while (rightTree != NULL) {
        succ = rightTree->data; //if there was no right part, then succ would have nothing (2)
        rightTree = rightTree->left;
    }

    return {pred,succ};
}

void insertBST (BinaryTreeNode* &root, int data) {
    if (root == NULL) {
        root = new BinaryTreeNode(data);
    }

    if (data > root->data) {
        insertBST(root->right,data);
    }

    if (data < root->data) {
        insertBST(root->left,data);
    }
}

void insertData (BinaryTreeNode* &root) {
    int data;
    cout << "Enter data to insert in BST:" << endl;
    cin >> data;
    while (data != -1) {
        insertBST(root,data);
        cin >> data;
    }
}

int main () {

}
