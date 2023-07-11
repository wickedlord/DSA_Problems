#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool isIdentical(Node *r1, Node *r2)
    {
    if (r1 == NULL && r2 == NULL) {
        return true;
    }
    
    else if (r1 == NULL || r2 == NULL) {
        return false;
    }
    
    bool leftans = isIdentical(r1->left, r2->left);
    bool rightans = isIdentical(r1->right, r2->right);
    
    int d1 = r1->data;
    int d2 = r2->data;
    
    if (leftans && rightans && d1==d2) {
        return true;
    }
    
    else {
        return false;
    }
    }