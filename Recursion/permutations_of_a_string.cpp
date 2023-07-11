#include <bits/stdc++.h>
using namespace std;

void solve (vector<int> nums, vector<vector<int>>& ans, int index) {
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i=index; i<nums.size(); i++) {
        /*swapping so that every number comes at every place*/
        swap(nums[index], nums[i]);
        //recursive call
        solve(nums, ans, index+1);
        //backtracking so that we have the nums at its original form for
        //the next iteration.
        swap(nums[index], nums[i]);
    }
}

void display (vector<vector<int>> output) {
    for (int i=0; i<output.size(); i++) {
        cout << endl;
        for (int j=0; j<output[i].size(); j++) {
            cout << output[i].at(j) << " ";
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums,ans,index);
    display(ans);
    return ans;
}

int main () {
    vector<int> nums = {1,2,3};
    permute(nums);
}