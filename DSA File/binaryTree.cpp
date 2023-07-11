#include "bits/stdc++.h"
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (curr == inorder[i])
        {
            return i;
        }
    }
    return -1;
}
node *insertbst(node *root, int val)
{
    if (root == NULL)
    {
        return (new node(val));
    }
    if (val < root->data)
    {
        root->left = insertbst(root->left, val);
    }
    else
    {
        root->right = insertbst(root->right, val);
    }
    return root;
}

bool searchtree(node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key < root->data)
    {
        if (searchtree(root->left, key))
        {
            return true;
        }
    }
    if (key > root->data)
    {
        if (searchtree(root->right, key))
        {
            return true;
        }
    }
    return false;
}
node *inordersucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
node *deleteinbst(node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteinbst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteinbst(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3
        node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteinbst(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    node *root = NULL;
    root = insertbst(root, 5);
    insertbst(root, 1);
    insertbst(root, 3);
    insertbst(root, 4);
    insertbst(root, 2);
    insertbst(root, 7);
    inorder(root);
    cout << searchtree(root, 5) << endl;
    if (!searchtree(root, 5))
    {
        cout << "value is not in root" << endl;
    }
    else
    {
        deleteinbst(root, 5);
        inorder(root);
    }
    return 0;
}