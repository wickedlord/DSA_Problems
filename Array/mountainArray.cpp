#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int start=0; 
        int end=(arr.size())-1;
        int mid=(start+end)/2;
        
        while(start<end) {
            if (arr[mid]>arr[mid+1]) {
                end = mid;
            //we haven't done mid-1 beacuse if the element was
            //already the peak element, then we would have gone
            //to the left side of mountain
            }
            else start = mid + 1;
            mid = (start+end)/2;
        }
        return mid;
    }

int main () {
    vector<int> arr1 {0,4,3,2,1};
    //input definitely has to be mountain array in this question
    cout << peakIndexInMountainArray(arr1);
}