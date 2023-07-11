#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };


void convertToSortedDLL(TreeNode<int> *root, TreeNode<int> *&head) {
    if (root == NULL) {
        return;
    }

    convertToSortedDLL(root->right,head);

    root->right = head;
    if (head != NULL) {
        head->left = root;
    }
    
    head = root;

    convertToSortedDLL(root->left,head);
}

TreeNode<int>* mergeLL (TreeNode<int> *head1, TreeNode<int> *head2) {
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
                head1 = head->right;
            }

            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }

        else {
            if (head == NULL) {
                head = head2;
                tail = head2;
                head2 = head->right;
            }

            else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}


int counter(TreeNode<int> *head) {
    int count = 0;
    TreeNode<int> *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->right;
    }

    return count;
}


TreeNode<int> *convertToBST(TreeNode<int> *&head, int count) {
    if (count <= 0 || head == NULL) {
        return NULL;
    }

    TreeNode<int> *left = convertToBST(head,count/2);

    TreeNode<int> *root = head;
    root->left = left;
    head = head->right;

    root->right = convertToBST(head,count-(count/2)-1);
    return root;
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //step 1: convert into sorted doubly linked list
    TreeNode<int> *head1 = NULL;
    convertToSortedDLL(root1,head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertToSortedDLL(root2,head2);
    head2->left = NULL;

    //step 2: merge those linked lists
    TreeNode<int> *head = mergeLL(head1,head2);

    //step 3: convert to BST
    return convertToBST(head, counter(head));
}