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

class Solution{
    private:
    int height(struct Node* node){
        if (node == NULL) {
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left,right) + 1;
        
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if (root == NULL) {
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if (left && right && diff) {
            return true;
        }
        else return false;
    }
};

class Solution{
    // this will return a pair of bool and int representing height
    private:
    pair<bool,int> isBalancedFast(struct Node* node){
        if (node == NULL) {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(node->left);
        pair<int,int> right = isBalancedFast(node->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if (leftAns && rightAns && diff) {
            ans.first = true;
        }
        else ans.first = false;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};