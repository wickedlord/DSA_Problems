#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node (int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

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

void insertBST (Node* &root, int data) {
    if (root == NULL) {
        root = new Node(data);
    }

    if (data > root->data) {
        insertBST(root->right,data);
    }

    if (data < root->data) {
        insertBST(root->left,data);
    }
}

void insertData (Node* &root) {
    int data;
    cout << "Enter data to insert in BST:" << endl;
    cin >> data;
    while (data != -1) {
        insertBST(root,data);
        cin >> data;
    }
}

int minValue (Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

int maxValue (Node* root) {
    Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

Node* deletefromBST (Node* &root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == val) {

        //if the node to be deleted has no children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        //if the node to be deleted has 1 child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //if the node to be deleted has 2 children
        if (root->left != NULL && root->right != NULL) {
            //we have two choices either to get max value from the left side
            //or we can get the min value from the right side

            //taking min value from right side
            int mini = minValue(root->left);
            root->data = mini;
            root->right = deletefromBST(root->right,mini);
            return root;
        }
    }

    else if (root->data > val) {
        root->left = deletefromBST(root->left,val);
        return root;
    }

    else if (root->data < val) {
        root->right = deletefromBST(root->right,val);
        return root;
    }

}

int main () {
    Node* root = NULL;
    insertData(root);
    cout << "Printing the tree " << endl;
    levelOrderTraversal(root);
    cout << "The min value is : " << minValue(root) << endl;
    cout << "The max value is : " << maxValue(root) << endl;

    cout << "Deleting a node..." << endl;
    root = deletefromBST(root,30);
    cout << "Printing the tree " << endl;
    levelOrderTraversal(root);
}