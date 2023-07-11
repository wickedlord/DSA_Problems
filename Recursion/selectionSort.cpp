#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    if (n==1 || n==0) {
        return;
    }
    int lowest=arr[0];
    for (int i=0; i<n; i++) {
        if (arr[i]<lowest) {
            lowest=arr[i];
        }
    }
    swap(arr[0],lowest);
    selectionSort(arr,n-1);
}

int main () {
    int arr[5] = {9,8,7,6,5};
    selectionSort(arr,5);
    for (int i=0; i<5; i++) {
        cout << arr[i] << " " ;
    }
}