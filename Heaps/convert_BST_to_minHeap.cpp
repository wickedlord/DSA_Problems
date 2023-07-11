#include <bits/stdc++.h>
using namespace std;

struct Node {
 
    int data;
    Node *left, *right;
};

struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//main code starts here

void inOrderFinder (Node* root, vector<int> &inOrder) {
    if (root == NULL) {
        return;
    }
    inOrderFinder(root->left,inOrder);
    inOrder.push_back(root->data);
    inOrderFinder(root->right,inOrder);
}

void inOrderToHeap (Node* root, vector<int> &inOrder, int &index) {
    if (root == NULL) {
        return;
    }

    root->data = inOrder[index++];
    inOrderToHeap(root->left,inOrder,index);
    inOrderToHeap(root->right,inOrder,index);
}

int main () {
    // BST formation
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    //we have two conditions:
    //we have a binary search tree which follows L < R
    //and we have minHeap which follows N<L and N<R
    //combining them we have N<L<R which is the preorder traversla order.
    //so traversing the found sorted inorder from BST to create a minHeap.
    vector<int> inOrder;
    inOrderFinder(root,inOrder);
    int index = 0;
    inOrderToHeap(root,inOrder,index);

}