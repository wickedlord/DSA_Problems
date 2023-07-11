#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode{

        public :
            T data;
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

void inorderTraversal(TreeNode<int> *root, vector<int> &inorder) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right,inorder);
}


void mergeArrays(vector<int> &in_root1, vector<int> &in_root2, int m, int n) {
    int i = 0; //for arr1
    int j = 0; //for arr2
    vector<int> mergedArr; //array to be finally returned

    //remember to initialize the array to 0 as it might return
    //garbage values in it

    int k=0; //for mergedArr
    while (i < m && j < n)
    {
        if (in_root1[i] < in_root2[j])
        {
            mergedArr.push_back(in_root1[i]);
            i++;
        }
        else
        {
            mergedArr.push_back(in_root2[j]);
            j++;
        }
    }
    //till here we have merged the array till the size of the
    //array whichever is actually smaller

    while (j < n)
    {
        mergedArr.push_back(in_root2[j]);
        j++;
    }

    // only one of these while loop will be executed and the
    //the one which will be executed will used to add the
    //remaining elements of the larger array.

    while (i < m)
    {
        mergedArr.push_back(in_root1[i]);
        i++;
    }
    
    in_root1.clear();
    for (int x=0; x<m+n; x++) {
        in_root1.push_back(mergedArr[x]);
    }
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


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //step 1: convert into sorted array(get inorder)
    vector<int> in_root1;
    vector<int> in_root2;

    inorderTraversal(root1,in_root1);
    inorderTraversal(root2,in_root2);

    //step 2: merge two sorted arrays
    int size1 = in_root1.size();
    int size2 = in_root2.size();
    mergeArrays(in_root1,in_root2,size1,size2);

    //step3: create BST from inorder
    int start = 0;
    int end = in_root1.size() - 1;
    return convertToBalancedBST(start,end,in_root1);
}