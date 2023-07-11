#include<bits/stdc++.h>
using namespace std;

int firstOcc (int arr[], int size, int key) {
    int start=0, end=size-1;
    int mid = (start+end)/2;
    int answer = -1;

    while (start <= end) {

        if (arr[mid]==key) {
            answer = mid;
            end = mid-1;
        }

        else if (arr[mid]<key) {
            start = mid+1;
        }

        else end = mid-1;

        mid = (start+end)/2;
    }
    return answer;
}

int lastOcc (int arr[], int size, int key) {
    int start=0, end=size-1;
    int mid = (start+end)/2;
    int answer = -1;

    while (start <= end) {
        if (arr[mid]==key) {
            answer = mid;
            start = mid+1;
        }

        else if (arr[mid]<key) {
            start = mid+1;
        }

        else end = mid-1;

        mid = (start+end)/2;
    }
    return answer;
}

int main () {
    // pair<int, int> p;
    int arr [14] {1,2,3,4,4,4,4,4,4,4,4,5,6,7};
    // p.first = firstOcc(arr, 14, 4);
    // p.second = lastOcc(arr, 14, 4);
    cout << firstOcc(arr, 14, 4) << endl;
    cout << lastOcc(arr, 14, 4) << endl;
}