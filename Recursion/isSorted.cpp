#include <bits/stdc++.h>
using namespace std;

bool isSorted (int arr[], int size) {
    //base case
    if (size==0||size==1) {
        return true;
    }

    if (arr[0]>arr[1]) {
        return false;
    }
    bool ans = isSorted(arr+1,size-1);
    return ans;
}

int main () {
    int arr[5] = {2,6,8,10,12};
    cout << isSorted(arr,5);
}