#include <iostream>
using namespace std;

int partition (int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;

    for (int i=s+1; i<=e; i++) {
        if (arr[i]<pivot) {
            count ++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i=s, j=e;
    while (i < pivotIndex && j > pivotIndex) {
        if (arr[i]<=pivot)
            i++;
        if (arr[j]>pivot)
            j--;
        else swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort (int arr[], int s, int e) {
    if (s>=e) {
        return;
    }
    
    int p = partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main () {
    int arr[5] = {9,8,7,6,5};

    quickSort(arr,0,4);

    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
}