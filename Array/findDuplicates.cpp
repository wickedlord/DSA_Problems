// leetcode question to find duplicate elements in an array 

#include<bits/stdc++.h> //this is used to import all standard library
#include<vector>
using namespace std;

//this function is created to solve the question
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> output_vector;
    sort(nums.begin(), nums.end()); //sorts element in asc. order
    for (int i=1; i<nums.size(); i++) {
        if (nums[i]==nums[i-1]) {
            output_vector.push_back(nums[i]);
        }
    }
    return output_vector;
}

int main () {
    vector<int> arr1 {4,3,2,7,8,2,3,1};
    for (auto x : findDuplicates(arr1)) {
        cout << x << " ";
    }
}