#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> arr, int n) {
    for (int i=0; i<n-1; i++) {
    //above loop is for taking each element of the array one by
    //one for comparison.
        for (int j=i+1; j<n; j++) {
        //this loop is for comparing the selected element of
        //the array with elements in front of the array
            if (arr[j] < arr[i])
            //i.e. if the element after the selected one is smaller
            swap(arr[i],arr[j]);
            //swap the selected element with the one smaller
            //than it which we we ahve found using this algo
        }
    }
    //printing the output of the above algo
    for (int k=0; k<n; k++) {
        cout << arr[k] << " ";
    }
}

int main () {
    vector<int> arr {6,5,7,3,4};
    selectionSort(arr,5);
}