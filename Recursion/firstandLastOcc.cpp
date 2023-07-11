#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    if (s<=e) {
        if (arr[mid]==key) {
            ans = mid;
            n = (n/2)+1;
            if ((firstOcc(arr,n,key))!=-1) {
                return ans;
            }
        }
        if (arr[mid]>key) {
            n = (n/2)+1;
            if ((firstOcc(arr,n,key))!=-1) {
                return ans;
            }
        }
    }
    return ans;
}

int main () {
    int arr [5] = {0,1,1,5,6};
    cout << firstOcc(arr,5,1);
}