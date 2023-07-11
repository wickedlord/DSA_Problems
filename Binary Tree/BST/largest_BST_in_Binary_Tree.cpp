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


class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};


info solve(TreeNode<int>* root, int &ans) {
    if (root == NULL) {
        return {INT_MIN,INT_MAX,true,0};
        //send INT_MIN as maxi so that we can compare it when currNode.max
        //same for INT_MAX
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    //check for the three conditions for it to be bst
    if ((left.isBST) && (right.isBST) && (left.maxi < root->data) && (right.mini > root->data)) {
        currNode.isBST = true;
    }

    else currNode.isBST = false;

    if (currNode.isBST) {
        ans = max(ans,currNode.size);
    }

    return currNode;
}


int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info ans = solve(root,maxSize);
    return maxSize;
}
