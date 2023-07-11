#include <bits/stdc++.h>
using namespace std;

void solve (vector<int> nums, vector<vector<int>> &output, int index, vector<int> ans) {
    if (index>=nums.size()) {
        output.push_back(ans);
        return;
    }

    // exclude wala case
    solve (nums, output, index+1, ans);

    //include wala case
    int element = nums[index];
    ans.push_back(element);
    solve (nums, output, index+1, ans);
}

void display (vector<vector<int>> output) {
    for (int i=0; i<output.size(); i++) {
        cout << endl;
        for (int j=0; j<output[i].size(); j++) {
            cout << output[i].at(j) << " ";
        }
    }
}

vector<vector<int>> subsets_of_set (vector<int> nums) {
    vector<vector<int>> output;
    int index=0;
    vector<int> ans;
    solve(nums, output, index, ans);
    display(output);
    return output;
}

int main () {
    vector<int> nums {1,2,3};
    subsets_of_set(nums);
    /*for this question, check video 37, we have to understand
    it using a sort of tree where we include and exclude subsets*/
}