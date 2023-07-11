#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> arr, int n) {
    int s=0; 
    int e=n-1;
    int mid=(s+e)/2;
    
    while (s<e) {
        //first we'll check if we are on the upper line of the
        //graph or the lower line. for that we'll compare mid
        //with the first element of the array. if it's greater
        //shift the start, otherwise shift end.
        if (arr[mid]>=arr[0]) {
            s=mid+1;
        }
        else e=mid;
        mid=(s+e)/2;
    }
    //can return s or e as on dry run, we find that both of them
    //actually turn out to be the same at the end.
    return s;
}

int binarySearch (vector<int>& arr, int s, int e, int key) {
    int start=s, end=e;
    int mid=(start+end)/2;

    while (start <= end) {
        if (arr[mid]==key) {
            return mid;
        }

        if (arr[mid]<key) {
            //since the array is sorted, moving to the next
            //element will give a greater value and hence we'll
            //be more closer to the right answer
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }

        mid = (start+end)/2;

    }
    //if key is not found we are going to return -1.
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = findPivot(arr,n);
    //using the below logic to find if the key is in lower line
    //of the graph or upper, then using pivot, we can apply
    //binary search in that line.
    if ((k >= arr[pivot]) && (k <= arr[n-1])) {
        return binarySearch(arr,pivot,n-1,k);
    }
    else return binarySearch(arr,0,pivot-1,k);
}

int main () {
    vector<int> arr {2, 4, 5, 6, 8, 9, 1};
    cout << findPosition(arr,7,6);
}