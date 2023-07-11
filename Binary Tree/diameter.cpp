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

class Solution {
    // a solution in O(n^2) but a clear less messy one.
  private:
    int height (Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left,right) + 1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = diameter(root->left);
        int right = diameter(root->right);
        
        int op1 = left;
        int op2 = right;
        int op3 = height(root->left) + height(root->right) + 1;
        
        int ans = max(op1, max(op2,op3));
        return ans;
    }
};

// a O(n) solution
class Solution {
    private:
        pair<int,int> diameterFast (Node* root) {
            if (root == NULL) {
                pair<int,int> p = make_pair(0,0);
                return p;
            }
            
            pair<int,int> left = diameterFast(root->left);
            pair<int,int> right = diameterFast(root->right);
            
            int op1 = left.first;
            int op2 = right.first;
            int op3 = left.second + right.second + 1;
            
            pair<int, int> ans;
            ans.first = max(op1, max(op2,op3));
            ans.second = max(left.second, right.second) + 1;
            
            return ans;
        }
    public:
        // Function to return the diameter of a Binary Tree.
        int diameter(Node* root) {
            pair<int, int> ans = diameterFast(root);
            return ans.first;
        }
};