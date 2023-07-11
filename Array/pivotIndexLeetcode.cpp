#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int start=0;
        int end=nums.size() - 1;
        int mid=(start+end)/2;
        
        while (start<=end) {
            int start_sum=0;
            int end_sum=0;
            for (int i=0; i<mid; i++) {
                start_sum = start_sum + nums[i];
            }
            for (int j=(nums.size())-1; j>mid; j--) {
                end_sum = end_sum + nums[j];
            }
            if (start_sum==end_sum) {
                return mid;
            }
            else if (start_sum>end_sum) {
                end=mid-1;
            }
            else start=mid+1;
            mid = (start+end)/2;
        }
        return -1;
    }

int main () {
    vector<int> nums {-2,-5,1,-2,-2,-3};
    cout << pivotIndex(nums);
}