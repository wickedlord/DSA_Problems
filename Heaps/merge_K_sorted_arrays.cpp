#include <bits/stdc++.h> 
using namespace std;
class node {
    public:
        int data;
        int i;
        int j;

        node(int data, int row, int col) {
            this->data = data;
            i = row;
            j = col;
        }
};

class compare {
    public:
        bool operator ()(node* a,node* b) {
            return (a->data > b->data);
        }     
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    //ek minheap create krli jisme node jaega jisme data and uski row,col no. jaega
    priority_queue<node*,vector<node*>,compare> pq;
    //starting elements of all the rows are pushed into it
    for (int i=0; i<k; i++) {
        node* temp = new node(kArrays[i][0],i,0);
        pq.push(temp);
    }

    vector<int> ans;

    while (!pq.empty()) {
        node* temp = pq.top();
        pq.pop();

        ans.push_back(temp->data);
        int i = temp->i;
        int j = temp->j;
        //check if the element was not the last element of that array
        if (j+1 < kArrays[i].size()) {
            //agar nhi, to uska next element usme push krdo
            node* next = new node(kArrays[i][j+1],i,j+1);
            pq.push(next);
        }
        
    }

    //saare comparison ke baad array bhar jaegi
    return ans;
}
