#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int leftchild = 2*i+1;
    int rightchild = 2*i+2; 

    if (leftchild < n && arr[smallest] > arr[leftchild]) {
        smallest = leftchild;
    }

    if (rightchild < n && arr[smallest] > arr[rightchild]) {
        smallest = rightchild;
    }

    if (smallest != i) {
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i=n/2-1; i>=0; i--) {
        heapify(arr,n,i);
    }

    return arr;
}
