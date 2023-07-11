//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    Node* createMapping(Node* root, int target, map<Node*,Node*> &NodeToParent) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        NodeToParent[root] = NULL;
        
        //doing level order traversal fo this
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if (front->data == target) {
                res = front;
            }
            
            if (front->left) {
                NodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if (front->right) {
                NodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        
        return res;
    }
    
    void burnTree (Node* targetNode, map<Node*,Node*> &NodeToParent, int &ans) {
        map<Node*,bool> visited;
        //map to find which node has been visited
        queue<Node*> q;
        q.push(targetNode);
        
        while (!q.empty()) {
            bool flag = 0;
            //to check if something is inserted
            int size = q.size();
            
            for (int i=0; i<size; i++) { 
                //doing a for loop to execute all the roots that are
                //pushed into the queue at the same time
                Node* front = q.front();
                q.pop();
                
                if (front->left && !visited[front->left]) {
                    flag = 1;
                    visited[front->left] = 1;
                    //to mark a node is visited
                    q.push(front->left);
                }
                
                if (front->right && !visited[front->right]) {
                    flag = 1;
                    visited[front->right] = 1;
                    q.push(front->right);
                }
                
                if (NodeToParent[front] && !visited[NodeToParent[front]]) {
                    flag = 1;
                    visited[NodeToParent[front]] = 1;
                    q.push(NodeToParent[front]);
                }
            }
            
            if (flag) {
                ans++;
            }
            //if something has been inserted in the queue, then time
            //will be taken, so inc ans
        }
    }
    
    public:
    int minTime(Node* root, int target) 
    {
        int ans = 0;
        map<Node*,Node*> NodeToParent;
        //created a mapping to find out the parent node and find the
        //node from where do we have to start (target node)
        Node* targetNode = createMapping(root,target,NodeToParent);
        burnTree(targetNode,NodeToParent,ans);
        //main function
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends