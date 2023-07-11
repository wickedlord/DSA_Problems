#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int leftchild = 2*i;
    int rightchild = 2*i+1; 

    if (leftchild <= n && arr[largest] < arr[leftchild]) {
        largest = leftchild;
    }

    if (rightchild <= n && arr[largest] < arr[rightchild]) {
        largest = rightchild;
    }

    if (largest != i) {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while (size > 1) {
        //step1 : swap largest element at top with bottom one
        swap(arr[1],arr[size]);
        size--; //first element(largest) at fixed pos in the last, so no change.

        //step2 : call heapify func to place element at its right place.
        heapify(arr,size,1);
    }
}

int main () {
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    //creating heap first
    for (int i = n/2; i>0; i--) {
        heapify(arr,n,i);
    }

    heapSort(arr,n);
    for (int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
}