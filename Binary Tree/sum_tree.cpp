#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

pair<bool,int> isSumTreeFast(Node* root) {
    if (root == NULL) {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    
    if (root->left==NULL && root->right==NULL) {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    
    pair<bool,int> leftans = isSumTreeFast(root->left);
    pair<bool,int> rightans = isSumTreeFast(root->right);
    
    int sum = leftans.second + rightans.second;
    pair<bool,int> ans;
    if (leftans.first && rightans.first && sum == root->data) {
        ans.first = true;
        ans.second = 2*sum;
    }
    else {
        ans.first = false;
    }
    
    return ans;
}

bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }