#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree (Node* root) {
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter the data in the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data in the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}


void levelOrderTraversal (Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // being used as a separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) { //that means a level is completed
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }

        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }

    return;
}


void preOrder (Node* root) {
    //base case
    if (root == NULL) {
        return;
    }

    // NLR - Node left right
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder (Node* root) {
    //base case
    if (root == NULL) {
        return;
    }

    // LNR - left node right
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


void postOrder (Node* root) {
    //base case
    if (root == NULL) {
        return;
    }

    // LRN - left right node 
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}


void buildfromLevelOrder (Node* &root) {
    queue<Node*> q;
    cout << "Enter the data : ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter the data for the left node of " << temp->data << " :";
        int leftData = 0;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the data for the right node of " << temp->data << " :";
        int rightData = 0;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}


int main () {
    Node* root = NULL;

    // //building of a tree
    // // the data is 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);

    // //level order traversal
    // cout << "Level order is : "  << endl;
    // levelOrderTraversal(root);
    // cout << endl;

    // cout << "Preorder is : ";
    // preOrder(root);
    // cout << endl;

    // cout << "Inorder is : ";
    // inOrder(root);
    // cout << endl;

    // cout << "Postorder is : ";
    // postOrder(root);
    // cout << endl;

    buildfromLevelOrder(root);
    cout << endl;
    levelOrderTraversal(root);
}