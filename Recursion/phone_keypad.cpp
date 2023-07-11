#include <bits/stdc++.h>
using namespace std;

void solve (string digit, int index, vector<string>& ans, string output, string mapping[]) {
    if (index>=digit.length()) {
        ans.push_back(output);
        return;
    }

    int number = digit[index]-'0';
    string value = mapping[number];
    

    for (int i=0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve(digit, index+1, ans, output, mapping);
        output.pop_back();
    }
}

void display(vector<string> ans) {
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

vector<string> letterCombinations (string digit) {
    vector<string> ans;
    if (digit.length()==0) {
        return ans;
    }
    int index=0;
    string output="";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digit, index, ans, output, mapping);
    display(ans);
    return ans;
}

int main () {
    string digits = "23";
    letterCombinations(digits);
}