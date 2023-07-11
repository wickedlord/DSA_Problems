#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int nonZero = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=0) {
                swap(nums[i],nums[nonZero]);
                nonZero++;
            }
        }
    }
//code only works when starting index is 0.
//further check the problem statement on leetcode.