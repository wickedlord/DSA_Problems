//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int indexToPosition (int in[], int inOrderStart, int inOrderEnd, int element) {
        for (int i=inOrderStart; i<=inOrderEnd; i++) {
            if (in[i] == element) {
                return i;
            } 
        }
        return -1;
    //created this function to find the preorder element in inorder
    }
    
    
    Node* solve(int in[],int pre[], int n, int &index,int inOrderStart, int inOrderEnd) {
        if (index >= n || inOrderStart > inOrderEnd) {
            return NULL;
        }
        
        int element = pre[index++];
        Node *root = new Node(element);
        int position = indexToPosition(in,inOrderStart,inOrderEnd,element);
        
        root->left = solve(in,pre,n,index,inOrderStart,position-1);
        //left side of inorder is passed
        root->right = solve(in,pre,n,index,position+1,inOrderEnd);
        //right side of preoder is passed.
        
        return root;
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        Node* root = solve(in,pre,n,index,0,n-1);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends